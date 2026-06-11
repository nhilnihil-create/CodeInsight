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
	vector<int> b(n-1);
	rep(i, n-1) cin >> b[i];
	ll sum = b[n - 2] + b[0];
	rep(i, n - 2) {
		sum += min(b[i], b[i + 1]);
	}
	cout << sum;
}