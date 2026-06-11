

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


const int BIG_NUM = 1e8;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	set<int> s;
	s.insert(0);
	vector<int> t;
	t.emplace_back(0);
	int next = a[0];
	while (s.find(next) == s.end()) {
		t.emplace_back(next);
		s.insert(next);
		next = a[next];
		
	}

	int loopBegin = 0;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == next) {
			loopBegin = i;
			break;
		}
	}
	if (k >= loopBegin) {
		k -= loopBegin;
		int l = t.size() - loopBegin;
		k %= l;
		cout << t[k + loopBegin] + 1 << endl;
	}
	else {
		cout << t[k] + 1 << endl;
	}
}