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
	string n;
	cin >> n;

	int c = 0;
	for (int i = 0; i < n.size(); i++) {
		c += n.at(i) - '0';
	}

	if (c % 9 == 0) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;

	return 0;
}