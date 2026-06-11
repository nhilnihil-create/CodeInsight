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

//解説ac

int main()
{
	ll x;cin >> x;
	ll y = 100;
	ll i = 0;
	while (y < x) {
		y += y / 100;
		i++;

	}cout << i;

}
