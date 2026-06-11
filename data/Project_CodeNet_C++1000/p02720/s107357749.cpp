#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <math.h> 
#include <iomanip>
#include <string.h>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define PI 3.14159265358979323846264338327950L

#define INF 0x3f3f3f3f
//const int N = 2e5 + 5;
   
int sum(int l, int r) {

	return (l + r)*(r - l + 1) / 2;

}

int gcd(int a, int b) {

	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}

}

int32_t  main() {

	IOS;

	int K;

	cin >> K;

	queue<int> q;

	vector<int> ans;
	for (int i = 1; i <= 9; i++) {
		q.push(i);
		ans.push_back(i);
	}

	if (K <= ans.size()) {

		cout << ans[K - 1] << endl;
		return 0;
	}

	while (true) {

		if (ans.size() >= K) {
			cout << ans[K - 1] << endl;
			break;
		}

		int tmp = q.front();

		q.pop();

		for (int i = -1; i <= 1; i++) {

			int curr = tmp % 10;

			curr += i;
			if (curr < 0 || curr > 9)
				continue;
			int newN = tmp * 10 + curr;

			q.push(newN);

			ans.push_back(newN);


		}


	}



}
