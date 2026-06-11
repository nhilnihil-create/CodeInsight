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
	ll a, b, k;
	cin >> a >> b >> k;
	k -= a;
	if(k>=0){
		ll v = 0;
		ll oo = max(v, b - k);
		cout << 0 << " " << oo;
	}
	else {
		cout << -k << " " << b;
	}
}