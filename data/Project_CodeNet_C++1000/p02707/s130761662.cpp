

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
	
	int n;
	cin >> n;

	map<int, int> m;
	for (int i = 0; i < n - 1; i++) {
		int a;
		cin >> a;
		m[a]++;
	}

	for (int i = 1; i <= n; i++) {
		cout << m[i] << endl;
	}


}