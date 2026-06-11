#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	int X, N, diff=100, ans;
	ll K, num=0;
	set<int> st;

	cin >> X >> N;
	vector<int> p(N);

	rep(i,N) cin >> p[i];
	rep(i, N) st.insert(p[i]);

	rep(i, 102){
		if (st.count(i) == 0){
			if (diff > abs(X - i)){
				diff = abs(X - i);
				ans = i;
			}
		}
	}

	cout << ans << endl;

	return 0;
}