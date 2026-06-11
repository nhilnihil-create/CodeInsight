#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
int main() {
	int n;
	cin >> n;
	int s1 = 0, s2 = 0;
	vector<string> S1(n);
	vector<string> S2(n);
	for (int i = 0; i < n; i++) {
		cin >> S1[i] >> S2[i];
		if (S1[i].compare(S2[i]) < 0) {
			s2 += 3;
		}
		else if (S1[i].compare(S2[i]) == 0) {
			s1++;
			s2++;
		}
		else {
			s1 += 3;

		}
	}
		cout << s1 << " " << s2 << endl;
}