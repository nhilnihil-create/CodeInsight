#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>
#include <cmath>
#define ll long long

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	vector<int> a(N);


	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	set<int> s;

	bool poss = true;

	for (int i = 0; i < N; i++) {

		if (s.find(a[i]) == s.end()) {
			s.insert(a[i]);
		}
		else {
			poss = false;
			break;
		}
	}

	if (poss) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}