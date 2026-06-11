

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;



int main() {
	ll a, b, n;
	cin >> a >> b >> n;

	ll num = min(b - 1, n);

	cout << (num * a) / b << endl;
}