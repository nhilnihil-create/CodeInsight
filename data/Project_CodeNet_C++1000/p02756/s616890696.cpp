#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;


int main()
{
	string S;
	int Q;
	cin >> S;
	cin >> Q;

	vector<int> q1(Q);
	vector<int> q2(Q);
	vector<char> q3(Q);
	int reverse_cnt = 0;

	for (int i = 0; i < Q; ++i)
	{
		cin >> q1[i];
		if (q1[i] != 1) {
			cin >> q2[i] >> q3[i];
		}
		else {
			reverse_cnt++;
		}
	}

	bool reverse_flag;
	if (reverse_cnt % 2 == 1) {
		reverse(S.begin(), S.end());
	}

	string left;
	string right;

	for (int i = 0; i < Q; ++i)
	{
		if (q1[i] == 1) {
			reverse_cnt -= 1;
		}
		else {
			if (reverse_cnt % 2 == 0) {
				if (q2[i] == 1) {
					left.push_back(q3[i]);
				}
				else {
					right.push_back(q3[i]);
				}
			}
			else {
				if (q2[i] == 1) {
					right.push_back(q3[i]);
				}
				else {
					left.push_back(q3[i]);
				}
			}
		}
	}

	reverse(left.begin(), left.end());
	cout << left + S + right<< endl;
	return 0;
}