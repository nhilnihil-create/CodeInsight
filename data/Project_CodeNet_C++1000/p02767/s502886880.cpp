#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
	int n;
  	cin >> n;
  	vector<int> x(n);
  	rep(i, n) cin >> x[i];
  	
  	int ans = 1e9;
  	for(int i = 1; i <= 100; i++){
      	int p = 0;
      	rep(j, n) p += (x[j]-i)*(x[j]-i);
    	ans = min(ans, p);
    }
	
  	cout << ans << endl;
}