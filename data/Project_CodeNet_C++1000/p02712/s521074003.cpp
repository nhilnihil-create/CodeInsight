
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main(int argc, char* argv[]) {
	int n;
	cin >> n; 

	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) {
			continue;
		}

		if (i % 5 == 0) {
			continue;
		}

		sum += i;
	}
	
	cout << sum << endl;
}