#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

int main() {
	int n, ans;
	double d, x, y;
	while(cin >> n >> d) {
		ans = 0;
		while(n--) {
			cin >> x >> y;
			if(sqrt(x*x+y*y) <= d)
				ans++;
		}
		cout << ans << endl;
	} 
}