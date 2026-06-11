#include <iostream>
using namespace std;

#define LIM	123456*2
bool p[LIM];

void init() {
	fill(p, p + LIM, true); //true????´???°
	p[0] = p[1] = false;
	for (int i = 4; i < LIM; i += 2) p[i] = false;
	for (int i = 3; i < LIM; i += 2) 
		if (p[i]) for (int j = i * 2; j < LIM; j += i) p[j] = false;
}

int main() {
	init();
	int n;
	while (cin >> n, n) {
		int cnt = 0;
		for (int i = n + 1; i <= n * 2; i++) if (p[i] == true)cnt++;
		cout << cnt << endl;
	}
}