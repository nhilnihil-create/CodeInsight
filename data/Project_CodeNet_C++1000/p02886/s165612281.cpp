#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  	int n;
  	cin >> n;
  
  	vector<int> d(n);
  	rep(i, n) cin >> d.at(i);
  
  	int ans=0;
  	rep(i, n) rep(j, n){
      if(i>=j) continue;
      else{
        ans += d.at(i)*d.at(j);
      }
    }
  	cout << ans << endl;
  	return 0;  
}
