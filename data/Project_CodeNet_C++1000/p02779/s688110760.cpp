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
	int N;
	cin >> N;
	set<int> st;
	int t;
	rep(i, N) {
		cin >> t;
		st.insert(t);
	}
	
	if (st.size() == N) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	
	return 0;
} 