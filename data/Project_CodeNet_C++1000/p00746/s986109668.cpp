#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
using namespace std;
struct P {
	int x, y;//??????
};
int main() {
	int n;
	while (cin >> n&&n != 0) {
		int minx = 0, maxx = 1;
		int miny = 0, maxy = 1;
		map<int, P>a;
		a.insert(map<int, P>::value_type(0, P{ 0,0 }));
		for (int z = 1; z < n; z++) {
			int m, d;
			cin >> m >> d;
			P t = a[m];
			if (d == 0) {
				t.x--;
				minx = min(t.x, minx);
			}
			else if (d == 1) {
				t.y++;
				maxy = max(t.y + 1, maxy);
			}
			else if (d == 2) {
				t.x++;
				maxx = max(t.x + 1, maxx);
			}
			else {
				t.y--;
				miny = min(t.y, miny);
			}
			a.insert(map<int, P>::value_type(z, t));
		}
		cout << maxx - minx << " " << maxy - miny << endl;
	}
}