#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
#define pq priority_queue
#define P pair<int,int>
#define P2 pair<int,P>
#define P3 pair<int,P2>
typedef long long ll; typedef long double ld;
using namespace std;
const int INF=1e9, MOD=1e9+7, around[]={0,1,1,-1,-1,0,-1,1,0,0};
const ll LINF=1e18;
const ld PI=abs(acos(-1));
int n,a[100010];
int dp[100010];

int main(){
	cin >> n;
	REP(i,0,n) cin >> a[i]; REP(i,0,n) dp[i]=INF;
	REP(i,0,n) *lower_bound(dp,dp+n,a[i])=a[i];
	cout << lower_bound(dp,dp+n,INF)-dp << endl;
	return 0;
}