#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n, k;
  	cin >> n >> k;
  	vector<int> h(n);
  	rep(i, n) cin >> h[i];
  	
  	sort(h.rbegin(), h.rend());
  	if(k > n) k = n;
  	rep(i, k) h[i] = 0;
  	
  	ll ans = 0;
  	rep(i, n) ans += h[i];
  	cout << ans << endl;
}