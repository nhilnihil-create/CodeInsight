
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

	while (1) {
		int n;
		cin >> n;
		if (n==0) break;

		int cnt = 0;
		for (int i = n + 1; i <= n * 2; i++) {
			bool flag = true;
			for (int j = 2; j*j <= i ; j++) {
				if (i%j == 0) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}