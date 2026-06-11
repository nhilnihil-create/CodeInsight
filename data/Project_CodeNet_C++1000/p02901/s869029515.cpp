#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const int Max_N=15;
const int Max_M=1e3+5;
int c[Max_M][Max_N];
const int INF=1e9;

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> a(M), b(M);
	rep(i,M){
		cin >> a[i] >> b[i];
		rep(j,b[i]) cin >> c[i][j];
		rep(j,b[i]) c[i][j]--;
	}
	vector<int> dp(1<<N,INF);
	dp[0]=0;
	rep(bit,1<<N){
		rep(i,M){
			int bit_next=bit;
			rep(j,b[i]) if(!(bit&1<<c[i][j])) bit_next+=1<<c[i][j];
			dp[bit_next]=min(dp[bit_next],dp[bit]+a[i]);
		}
	}
	if(dp[(1<<N)-1]==INF) cout << -1 << endl;
	else cout << dp[(1<<N)-1] << endl;

	return 0;
}