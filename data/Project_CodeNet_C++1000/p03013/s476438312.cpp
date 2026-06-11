#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cmath>

using ll = long long;
using namespace std;


int main() {
	ll n, m;
  	ll dp[100010];
  	cin >> n >> m;
  	ll broken[100010];
  
  	for(ll i=0;i<100010;i++) broken[i] = 1;
  
  	for(ll i=0;i<m;i++) {
    	ll t;
     	cin >> t;
      	broken[t] = 0;
    }
  	
  	dp[0] = 1;
  	dp[1] = broken[1];
  
  	for(ll i=2;i<100010;i++) {
      
    	dp[i] = (dp[i-1]*broken[i-1] + dp[i-2]*broken[i-2]) % 1000000007;
    }
  	
  	cout << dp[n] << endl;
}