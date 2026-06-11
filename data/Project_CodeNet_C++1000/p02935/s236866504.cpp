#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
ll Max = 10 + 1e12;
int N = 5 + 1e5;
int main()
{
	int n;
	cin >> n;
	vector<double> vv(n);
	rep(i, n) cin >> vv[i];
	sort(vv.begin(), vv.end());
	rep(i, n - 1) {
		double sum = (vv[0] + vv[1]) / 2;
		vv[0] = N;
		vv[1] = N;
		vv.push_back(sum);
		sort(vv.begin(), vv.end());
	}
	cout << vv[0];

}