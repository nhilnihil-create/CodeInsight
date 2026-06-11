

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
	int n, k;
	cin >> n >> k;

	set<int> s;

	for (int i = 0; i < k; i++) {
		int d;
		cin >> d;

		for (int j = 0; j < d; j++) {
			int a;
			cin >> a;
			a--;
			s.insert(a);
		}

	}

	cout << n - s.size() << endl;
}