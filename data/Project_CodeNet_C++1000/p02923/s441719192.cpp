#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n;
  	cin >> n;
  	vector<int> h(n);
  	rep(i, n) cin >> h[i];
  	
  	int ans = 0, tt = 0;
  	for(int i = n-1; i >= 0; i--){
    	if(h[i] <= h[i-1]) tt++;
      	else tt = 0;
      	ans = max(ans, tt);
    }
  
  	cout << ans << endl;
}