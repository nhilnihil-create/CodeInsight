#include<iostream>
#include<queue>
using namespace std;

int main() {
	int i, j, m, h, sc;
	char tmp, dum;
	while (1) {
		queue<char> c;
		while (1) {
			cin.get(tmp);
			if (tmp == '-')return 0;
			else if (tmp == '\n')break;
			c.push(tmp);
		}
		cin >> m;
		for (i = 0; i < m; i++) {
			cin >> h;
			for (j = 0; j < h; j++) {
				c.push(c.front());
				c.pop();
			}
		}
		sc = c.size();
		for (i = 0; i < sc; i++) {
			cout << c.front();
			c.pop();
		}
		cout << endl;
		cin.get(dum);
	}
	return 0;
}