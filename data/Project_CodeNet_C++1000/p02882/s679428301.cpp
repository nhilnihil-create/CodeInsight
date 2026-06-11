#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"
#include "string"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main() {
	cout << fixed << setprecision(10);
	int a, b, x;
	cin >> a >> b >> x;
	double w;
	if (a * a * b >= 2 * x) {
		w = atan((a * b * b / (2.0 * x)));
	}
	else {
		w = atan(2.0 * (a * a * b - x) / (a * a * a));

	}
	cout << 180 * w / acos(-1) << endl;
	return 0;
}