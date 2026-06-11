

#define _USE_MATH_DEFINES

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

const ll MOD = 1e9 + 7;


int main(int argc, char* argv[]) {
	
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int na = a / d;
	if (a % d != 0) {
		na++;
	}

	int nt = c / b;
	if (c % b != 0) {
		nt++;
	}

	if (na >= nt) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}