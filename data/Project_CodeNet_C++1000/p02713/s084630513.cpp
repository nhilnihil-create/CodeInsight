
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int gcd(int a, int b) {
	if (a > b) {
		swap(a, b);
	}
	
	if (a == 0) {
		return b;
	}

	return gcd(a, b % a);
	


}

int main(int argc, char* argv[]) {
	int k;
	cin >> k;

	ll sum = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int l = 1; l <= k; l++) {
				sum += gcd(i, gcd(j, l));


			}
		}
	}

	cout << sum << endl;
}