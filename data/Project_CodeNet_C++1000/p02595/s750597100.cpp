#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double n, d, c = 0;
	cin >> n >> d;
	while(n--) {
		double x, y;
		cin >> x >> y;
		x = abs(x);
		y = abs(y);
		double dis = pow(x, 2) + pow(y, 2);
		dis = pow(dis, 0.5);
		// cout << dis << endl;
		// cout << c << endl;
		if(dis <= d)
			c++;
	}	
	cout << c << "\n";
}