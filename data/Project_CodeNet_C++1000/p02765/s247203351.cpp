#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
	int n, r;
  	cin >> n >> r;
  	
  	int ans;
  	if(n < 10) ans = r+(10-n)*100;
  	else ans = r;
  	
  	cout << ans << endl;
}