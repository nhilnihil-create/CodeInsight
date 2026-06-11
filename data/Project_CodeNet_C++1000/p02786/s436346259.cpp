#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

ll res(ll x){
	if(x == 1) return 1;
  	
  	ll ans = 1;
  	ans += res(x/2) * 2;

  	return ans;
}

int main(){
	ll h;
  	cin >> h;
  
  	cout << res(h) << endl;; 
}