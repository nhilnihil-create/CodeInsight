#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int g(int start, int d) {
	vector<int> v1(10, 0), v2(10, 0);
	v1[start]++;
	for (int i = 2; i <= d; i++) {
		v2 = vector<int>(10, 0);
		for (int j = 0; j < 10; j++) {
			if (j > 0) v2[j] += v1[j - 1];
			v2[j] += v1[j];
			if (j < 9) v2[j] += v1[j + 1];
		}
		v1 = v2;
	}
	return accumulate(v1.begin(), v1.end(), 0);
}

string f(int n) {
	if (n < 10) {
		return string(1, '0' + n);
	}
	int c = 9;
	int start = 0;
	int digit = 0;
	for (int i = 2; ; i++) {
		bool flag = false;
		for (int j = 1; j < 10; j++) {
			int ret = g(j, i);
			if (c + ret >= n) {
				flag = true;
				start = j;
				break;
			}
			c += ret;
		}
		if (flag) {
			digit = i;
			break;
		}
	}
	string res(1, '0' + start);
	n -= c;
	while ((int)res.size() < digit) {
		if (res.back() > '0') {
			int ret = g(res.back() - '0' - 1, digit - res.size());
			if (ret >= n) {
				res.push_back(res.back() - 1);
				continue;
			} else {
				n -= ret;
				
			}
		}
		int ret = g(res.back() - '0', digit - res.size());
			if (ret >= n) {
				res.push_back(res.back());
				continue;
			} else {
				n -= ret;
				
			}
		ret = g(res.back() - '0' + 1, digit - res.size());
			if (ret >= n) {
				res.push_back(res.back() + 1);
				continue;
			} 
	}
	return res;
}

int main() {
	int k;
	cin >> k;
	cout << f(k) << endl;
}
