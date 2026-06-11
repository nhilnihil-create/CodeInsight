#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

std::string substrBack(std::string str, size_t pos, size_t len) {
	const size_t strLen = str.length();

	return str.substr(strLen - pos, len);
}

int main()
{
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> q(n);
	vector<int> per(n);
	rep(i, n) {
		cin >> p[i];
		per[i] = i + 1;
	}
	rep(i, n) {
		cin >> q[i];
	}
	int i = 1;
	int pNum = 0;
	int qNum = 0;
	do
	{
		bool isPOK = true;
		bool isQOK = true;
		rep(i, n) {
			if (per[i] != p[i]) {
				isPOK = false;
			}
			if (per[i] != q[i]) {
				isQOK = false;
			}
		}
		if (isPOK) {
			pNum = i;
		}
		if (isQOK) {
			qNum = i;
		}
		++i;
	} while (next_permutation(per.begin(), per.end()));
	int ans = abs(pNum - qNum);
	cout << ans << endl;
	//cout << fixed << setprecision(10) << ans << endl;
	system("pause");
}


