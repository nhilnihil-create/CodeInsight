#include <bits/stdc++.h>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define rep(i,a,b) for(int (i)=int(a);(i)<int(b);(i)++)
#define rrep(i,a,b) for(int (i)=int(a);(i)>=int(b);(i)--)

#define put(a) cout << (a) << endl
#define puts(a) cout << (a) << " "

#define llint long long int

#define INF (long long)(1e9+1)
#define MOD (long long)(1e9+7)
#define INF64 (long long)(1e18+1)

#define F first
#define S second

#define Pii  pair<int,int>
#define Pll  pair<long long,long long>
#define Piii pair<int,pair<int,int>>
#define Plll pair<long long,pair<long long,long long>>

#define Vll(a,b,c)    vector<vector<long long>> (a)((b),vector<long long>((c))
#define Vlll(a,b,c,d) vector<vector<vector<long long>>> (a)((b),vector<vector<long long>>((c),vector<long long>((d)))

#define MAX_N 1000000



int main (void)
{
	llint N,H;
	cin >> H >> N;
	vector<pair<llint, llint> > P(N);
	rep(i,0,N) {
		cin >> P[i].F >> P[i].S;
	}

	vector<llint> dp(H+1e4+1,INF64);

	dp[0] = 0;

	for(llint i=0;i<H;i++) {
		if (dp[i] < INF64) {
			for(llint j=0;j<N;j++) {
				dp[i+P[j].F] = min(dp[i+P[j].F], dp[i]+P[j].S);
			}
		}
	}

	llint ans=INF64;

	for(llint i=H;i<=H+1e4;i++){
		ans = min(ans,dp[i]);
	}

	cout << ans << endl;

	return 0;
}
