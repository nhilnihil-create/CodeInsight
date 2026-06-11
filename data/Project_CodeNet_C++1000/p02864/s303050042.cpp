#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int n, k; cin>>n>>k;
	ll h[303];
	h[0]=0;
	for(int i=1; i<=n; i++){
		cin>>h[i];
	}
	ll dp[303][303][303];
	const ll INF=1e18;
	for(int i=0; i<=n; i++) for(int j=0; j<=k; j++) for(int l=0; l<=i; l++) dp[i][j][l]=INF;
	dp[0][0][0]=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<=k; j++){
			for(int l=0; l<=i; l++){
				dp[i+1][j][i+1]=min(dp[i+1][j][i+1], dp[i][j][l]+max(0ll, h[i+1]-h[l]));
				if(j+1<=k) dp[i+1][j+1][l]=min(dp[i+1][j+1][l], dp[i][j][l]);
			}
		}
	}
	ll ans=INF;
	for(int i=0; i<=k; i++){
		for(int j=0; j<=n; j++){
			ans=min(ans, dp[n][i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}