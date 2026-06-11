#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <cctype>
#include <random>

using namespace std;
typedef long long  ll;
const ll INF = 1000000007;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
	string n;
	cin >> n;
	reverse(n.begin(), n.end());
	switch (n[0]) {
	case '1':
	case '0':
	case '6':
	case '8':
		cout << "pon" << endl;
		break;
	case '2':
	case '4':
	case '5':
	case '7':
	case '9':
		cout << "hon" << endl;
		break;
	case '3':
		cout << "bon" << endl;
		break;

	}
	return 0;
}