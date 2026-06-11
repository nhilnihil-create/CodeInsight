#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;


int main() {
	int a, b, c, k,ans=0;
	cin >> a >> b >> c >> k;

		for (int i = 0; i < a; i++) {
			if (k == 0)break;
			ans++;
			k--;
		}

		for (int i = 0; i < b; i++) {
			if (k == 0)break;
			k--;
		}

		for (int i = 0; i < c; i++) {
			if (k == 0)break;
			ans--;
			k--;
		}
		cout << ans;
	
}