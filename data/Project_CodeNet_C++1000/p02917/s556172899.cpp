#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	cin >> n;
  	vector<int> a(n);
  	vector<int> b(n-1);
  	rep(i, n-1) cin >> b[i];
  
  	a[0] = b[0];
  	for(int i = 1; i < n; i++){
      	if(i == n-1){
          	a[i] = b[i-1];
         	break;
        }
    	a[i] = min(b[i-1], b[i]);
    }
  
  	int ans = 0;
  	rep(i, n) ans += a[i];
  	cout << ans << endl;
}