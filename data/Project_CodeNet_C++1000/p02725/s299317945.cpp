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
int Max = 10 + 1e8;
int main() 
{
	int Min = Max;
	int MAX = 0;
	int n, k;
	cin >> k >> n;
	vector<int> a(n);
	vector<int> sa(n);
	rep(i, n) cin >> a[i];
	rep(i, n-1) {
		sa[i] = a[i + 1] - a[i];
	}
	sa[n - 1] = a[0] + k - a[n - 1];
	rep(i, n) MAX = max(MAX, sa[i]);
	int ans = k - MAX;
	cout << ans;
}
