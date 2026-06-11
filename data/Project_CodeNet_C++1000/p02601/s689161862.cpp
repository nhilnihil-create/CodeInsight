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
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	int cnt = 0;
	while (a >= b) {
		b *= 2;
		cnt++;
	}
	while (b >= c) {
		c *= 2;
		cnt++;
	}
	if (cnt <= k) cout << "Yes";
	else cout << "No";
}