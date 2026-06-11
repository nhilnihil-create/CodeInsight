#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  	int n;
  	cin >> n;
  
  	vector<ll> a(n);
  	rep(i, n) cin >> a.at(i);
  
	ll maxValue=0, ans=0;
  	rep(i, n){
      if(a.at(i) < maxValue) ans += maxValue-a.at(i);
      else maxValue = a.at(i);
    }
  	cout << ans << endl;
  
  	return 0;
}
