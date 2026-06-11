

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
	int k, a, b;
	cin >> k >> a >> b;
	for (int i = a; i <= b; i++) {
		if (i % k == 0) {
			cout << "OK" << endl;
			return 0;
		}
	}

	cout << "NG" << endl;

}