#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep2(i,n) for(int i = -1; i < (n); i++)
#define PI 3.141592653589793

using namespace std;
using ll = long long;

const ll MA = 1000005;
int cnt[2];
int c[2];
int main() {

	int n;
	cin >> n;
	vector<int> p(n);
	int ans = 0;
	rep(i, n)cin >> p[i];

	for (int i = 1; i < n - 1; i++) {
		vector	<int> x;
		x.push_back(p[i - 1]);
		x.push_back(p[i]);
		x.push_back(p[i + 1]);

		sort(x.begin(), x.end());

		if (x[1] == p[i]) ans++; 

	}

	cout << ans << endl;

	return 0;
}
