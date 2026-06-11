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
ll Max = 10 + 1e9;
int main() 
{
	ll n, k;
	cin >> n >> k;
	n = n % k;
	while (n > k / 2) {
		n = abs(n - k);
	}
	cout << n;
}