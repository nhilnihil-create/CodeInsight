#include <bits/stdc++.h>

using namespace std;

int p[3] = {300000, 200000, 100000};

int main() {
	int x, y;
	cin >> x >> y;
	int ans;
	if(x <= 3){
		if(y <= 3){
			ans = p[x - 1] + p[y - 1];
			if(x == 1 && y == 1) ans += 400000;
		}
		else ans = p[x - 1];
	} 
	else{
		if(y <= 3) ans = p[y - 1];
		else ans = 0;
	}
	cout << ans << '\n';
}