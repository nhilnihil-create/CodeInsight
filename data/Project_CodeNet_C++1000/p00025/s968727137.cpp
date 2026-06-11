#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[4], b[4];
	while(cin >> a[0]) {
		bool v[10];
		memset(v, 0, sizeof v);
		v[a[0]] = 1;
		for(int i = 1; i < 4; i ++) {
			cin >> a[i];
			v[a[i]] = 1;
		}
		int hit = 0, blow = 0;
		for(int i = 0; i < 4; i ++) {
			cin >> b[i];
			if(a[i] == b[i])
				hit ++;
			if(v[b[i]])
				blow ++;
		}
		blow -= hit;
		cout << hit << ' ' << blow << '\n';
	}
	return 0;
}