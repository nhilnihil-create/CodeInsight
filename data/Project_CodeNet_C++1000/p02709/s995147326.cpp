//abc163_e.cpp
//Sun Apr 19 20:58:09 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<ll,ll> P;

int main(){
	int n;
	cin >> n;

	vector<P> yoji;
	for (int i=0;i<n;i++){
		ll a;
		cin >> a;
		yoji.push_back(P(a,i+1));
	}

	sort(yoji.begin(),yoji.end(),greater<P>());

	ll dp[n+2][n+2];
	for (int i=0;i<n+2;i++){
		for (int j=0;j<n+2;j++){
			dp[i][j] = 0;
		}
	}

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i+j<n){
				dp[i+1][j] = max(dp[i+1][j],dp[i][j]+yoji[i+j].first*abs(yoji[i+j].second-(i+1)));
				dp[i][j+1] = max(dp[i][j+1],dp[i][j]+yoji[i+j].first*abs(yoji[i+j].second-(n-j)));
			}
		}
	}

	ll ans = 0;
	for (int i=0;i<n;i++){
		ans = max(ans,dp[i][n-i]);
	}
	cout << ans << endl;
//	printf("%.4f\n",ans);
}