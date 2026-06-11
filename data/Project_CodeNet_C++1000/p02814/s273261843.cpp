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
const int INF = 1e9+1;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())
#define UP(v,x) (upper_bound(all(v),(x))-(v).begin())

int N, M, A[MAXN], B[MAXN];

int plcm(int x, int y){
	if (x>=INF && y>=INF) return INF;
	int lcm = x*y/__gcd(x,y);
	return min(lcm,INF);
}

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	int prb = -1;
	FOR(i,1,N){
		cin>>A[i];
		int tmp=A[i];
		while (tmp%2==0){
			tmp/=2;
			B[i]++;
		}
		if (prb == -1) prb = B[i];
		else if (prb != B[i]){
			cout<<0;
			exit(0);
		}
	}
	int totlcm = 1;
	FOR(i,1,N){
		totlcm = plcm(totlcm, A[i]/2);
	}
	if (totlcm > M) {
		cout<<0;
		exit(0);
	}
	int ans = (M-totlcm)/(2*totlcm);
	cout<<ans+1;
}
