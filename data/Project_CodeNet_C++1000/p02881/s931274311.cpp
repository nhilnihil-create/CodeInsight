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
	ll n;
	cin >> n;
	ll Min = Max;
	for (int i = 1;i <= sqrt(n);i++) {
		if (n % i == 0) {
			ll a = i + (n / i);
			Min = min(Min, a);
		}
	}
	cout << Min - 2;
}