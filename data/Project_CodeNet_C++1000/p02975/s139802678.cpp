
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	if (a[n - 1] == 0) {
		cout << "Yes";
	}
	else if (n % 3 == 0) {
		if (a[0] == 0 && a[n / 3 - 1] == 0 && a[n / 3] == a[n - 1]) {
			cout << "Yes";
		}
		else if(a[0] == a[n/3-1] && a[n/3] == a[2*n/3-1] && a[2*n/3] == a[n-1] && ((a[0] ^ a[n/3])^a[2*n/3]) == 0 ){
			cout << "Yes";
		}
		else {
			cout << "No";
		}
	}
	else {
		cout << "No";
	}

}

