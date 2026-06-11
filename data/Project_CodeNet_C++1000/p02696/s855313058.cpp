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
	int a;
	ll b, n;
	cin >> a >> b >> n;
	ll x = b - 1;
	if (n < b) x = n;
	cout << a*x / b;
}