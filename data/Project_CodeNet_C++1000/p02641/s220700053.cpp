#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int X, N;
	cin >> X >> N;
	map<int, bool> p;
	for (int i = 0; i < N; ++i) {
		int k;
		cin >> k;
		p[k] = true;
	}
	for (int i = 0;; ++i) {
		if (p[X - i] == false) {
			cout << X - i << endl;
			break;
		}
		else if (p[X + i] == false) {
			cout << X + i << endl;
			break;
		}
		else {
			continue;
		}

	}



	return 0;
}