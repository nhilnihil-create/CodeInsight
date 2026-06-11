#include <bits/stdc++.h>
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()

using namespace std;


int main(){
	// freopen("input.text" , "r" , stdin);
	// freopen("output.text" , "w" , stdout);

	int x ; cin >> x;
	int ans = 0;
	if(x >= 400 && x <= 599)ans = 8;
	if(x >= 600 && x <= 799)ans = 7;
	if(x >= 800 && x <= 999)ans = 6;
	if(x >= 1000 && x <= 1199)ans = 5;
	if(x >= 1200 && x <= 1399)ans = 4;
	if(x >= 1400 && x <= 1599)ans = 3;
	if(x >= 1600 && x <= 1799)ans = 2;
	if(x >= 1800 && x <= 1999)ans = 1;
	cout << ans << endl;
	return 0;
}