#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;

const ull ULL_MAX = 1.8446744e+19;

using namespace std;

int main() {

	int x, a;

	cin >> x >> a;

	int ans = x < a ? 0 : 10;
	cout << ans << endl;
}
