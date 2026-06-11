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

ll choose(ll a) { //aC2
	return (a - 1) * a / 2;
}
int main()
{
	int n;
	cin >> n;
	vector<string> ss(n);
	rep(i, n) cin >> ss[i];
	rep(i, n) sort(ss[i].begin(), ss[i].end());
	sort(ss.begin(), ss.end());
	vector<ll> cnt(n,1);
	ll sum = 0;
	int j = 0;
	rep(i, n-1) {
		if (ss[i] == ss[i + 1])
			cnt[j]++;
		else
			j++;
	}
	j++;
	rep(i, j) sum += choose(cnt[i]);
	cout << sum;

}