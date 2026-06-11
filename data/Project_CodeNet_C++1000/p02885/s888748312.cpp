#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int a, b;
  	cin >> a >> b;
  	
  	int ans = (a-2*b >= 0) ? a-2*b : 0;
  	cout << ans << endl;
}