#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <bitset>

#define _GLIBCXX_DEBUG
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define p_b push_back
#define e_b emplace_back
#define m_p make_pair
#define m_t make_tuple

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);

	rep(i, n) {
		cin >> vec[i];
	}

	ll c=0;

	for (int i = 0; i < n-1; i++) {
		if (vec[i] > vec[i + 1]) {
			c += vec[i] - vec[i + 1];
			vec[i + 1] += vec[i] - vec[i + 1];
		}
	}
	cout << c << endl;

	return 0;
}