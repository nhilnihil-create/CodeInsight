
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main(int argc, char* argv[]) {

	int k;
	cin >> k;

	if (k <= 9) {
		cout << k << endl;
		return 0;
	}


	set<ll> s;
	for (int i = 0; i < 9; i++) {
		s.insert(i+1);
	}

	int cnt = 9;
	while (1) {
		set<ll> newS;
		for (auto it = s.begin(); it != s.end(); it++) {
			ll num = *it;

			int n0 = num % 10;

			for (int i = -1; i <= 1; i++) {
				if (n0 + i < 0 || n0 + i >9) {
					continue;
				}

				if (cnt == k - 1) {
					cout << (num * 10 + n0 + i) << endl;
					return 0;
				}

				newS.insert(num * 10 + n0 + i);
				cnt++;
			}


		}

		s = newS;


	}

}