#include<bits/stdc++.h>

#define int long long
using namespace std;

const int mod = 1e9 + 7;
int fpow(int a, int b){
	int ans = 1;
  	while(b) {
      if (b&1) ans = (ans * a) % mod;
      a = (a*a) % mod;
      b >>= 1;
    }
  	return ans;
}
int32_t main() {
 	int n;
  	cin >> n;
  	cout << (fpow(10,n) - 2 * fpow(9,n) + fpow(8,n) + 2 * mod) % mod;
}
