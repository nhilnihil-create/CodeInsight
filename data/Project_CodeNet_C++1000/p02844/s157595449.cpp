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
	string s;
	cin >> n >> s;
	int ans = 0;
	rep(i, 1000) {
		string str = substrBack("000" + to_string(i),3, 3);
		int k = 0;
		rep(j, n) {
			if (str[k] == s[j]) {
				k++;
			}
			if (k == 3){
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	system("pause");
}


