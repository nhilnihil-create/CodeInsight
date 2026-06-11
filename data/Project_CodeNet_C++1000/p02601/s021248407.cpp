#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

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

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int A,B,C,K;
	cin>>A>>B>>C>>K;
	int ans = 0;
	while (B<=A){
		B*=2;
		ans++;
	}
	while (C<=B){
		C*=2;
		ans++;
	}
	if (ans <=K) cout<<"Yes";
	else cout<<"No";
}
