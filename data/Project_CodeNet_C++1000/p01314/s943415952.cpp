#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	vector<int> list;
	for (;;) {
		int buf;
		cin >> buf;
		if (!buf)break;
		list.push_back(buf);
	}
	for (int n : list) {
		int cnt = 0;
		for (int a = 1; a < n; a++) {
			for (int b = 1; (a*2 + b)*(b+1) <=n*2; b++) {
				if ((a*2 + b)*(b+1) == n * 2)cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}