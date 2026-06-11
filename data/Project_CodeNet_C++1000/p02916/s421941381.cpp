#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	cin >> n;
  	vector<int> a(n), b(n);
  	vector<int> c(n-1);
  	rep(i, n){
      int t;
      cin >> t; t--;
      a[i] = t;
    }
    rep(i, n) cin >> b[i];
  	rep(i, n-1) cin >> c[i];

  
  	int ans = 0;
  	rep(i, n){
    	ans += b[a[i]];
      	if(a[i]+1 == a[i+1]) ans += c[a[i]];
    }
  

    cout << ans << endl;
}