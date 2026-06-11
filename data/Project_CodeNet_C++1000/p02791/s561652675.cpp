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
	int n;
	cin >> n;
	vector<int> p(n);
	int Min = Max;
	int cnt = 0;
	rep(i, n) {
		int p;
		cin >> p;
		if (Min >= p) {
			cnt++;
			Min = p;
		}
	}
	cout << cnt;
}