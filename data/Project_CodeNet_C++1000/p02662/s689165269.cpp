#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0; i<n; i++)
#define sz(v) (v).begin(),(v).end()
#define prin(a) cout << #a << " = " << a<< endl
#define all(v) (v).begin(),(v).end()
typedef long long ll;

const int N = 3e3+10;
ll dp[2][N], v[N];
#define cur_dp dp[(i+1)&1]
#define ant_dp dp[i&1]
const ll MOD = 998244353;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, s; cin >> n >> s;
	fr(i,n) cin >> v[i];
	
	dp[0][0] = 1;
	fr(i,n){
		for(int j = 0; j<=s; j++){
			cur_dp[j] = 2*ant_dp[j]%MOD;
			if(v[i]<=j) cur_dp[j] = (ant_dp[j-v[i]]+cur_dp[j])%MOD;	
		}
	}
	cout << dp[n&1][s] << endl;
}