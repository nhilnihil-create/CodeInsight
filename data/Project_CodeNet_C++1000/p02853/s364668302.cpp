#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int x , y;
	cin >> x >> y;
	int ans = 0;
	if(x == 3) ans += 100000;
	if(x == 2) ans += 200000;
	if(x == 1) ans += 300000;
	if(y == 3) ans += 100000;
	if(y == 2) ans += 200000;
	if(y == 1) ans += 300000;
	if(x == 1 && y == 1) ans += 400000;
	cout << ans << endl;
	return 0;
}