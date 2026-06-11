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
	int w, h, x, y;
	cin >> w >> h >> x >> y;
	cout << (double)w * h / 2 << " ";
	if (w == x * 2 && h == y * 2) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}