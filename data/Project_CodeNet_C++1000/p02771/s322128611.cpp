#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int a, b, c;
  	cin >> a >> b >> c;
  
  	bool ans = true;
  	if(a == b) ans = false;
    if(b == c) ans = false;
  	if(a == c) ans = false;
	if(a == b && b == c) ans = true;
  
  	if(ans) cout << "No" << endl;
  	else cout << "Yes" << endl;
}