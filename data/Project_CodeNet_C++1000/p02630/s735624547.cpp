#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define int long long 
typedef pair<int,int>pi;
typedef vector<int>vi;

const int MAXN=100005;
const int MOD=1000000007;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())
#define UP(v,x) (upper_bound(all(v),(x))-(v).begin())

int N,A[MAXN],Q;
int freq[MAXN];

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	int ans = 0;
	FOR(i,1,N){
		cin>>A[i];
		freq[A[i]]++;
		ans += A[i];
	}
	cin>>Q;
	FOR(i,1,Q){
		int b, c; cin>>b>>c;
		ans += (c-b)*freq[b];
		freq[c] += freq[b];
		freq[b] = 0;
		cout<<ans<<"\n";
	}
}
