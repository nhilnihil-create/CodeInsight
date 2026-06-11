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
int N,A[MAXN];
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	FOR(i,1,N) cin>>A[i];
	int cash = 1000;
	int stocks = 0;
	if (A[1] < A[2]){
		stocks = cash/A[1];
		cash -= stocks * A[1];
	}
	FOR(i,2,N){
		cash += stocks * A[i];
		stocks = 0;
		if (i<N && A[i] < A[i+1]){
			stocks = cash/A[i];
			cash -= stocks * A[i];
		}
	}
	cout<<cash;
}
