#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<iomanip>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	 long double a, b, h, m;
	cin >> a >> b >> h >> m;
	 long double p, q, r;
	p = 30 * h + m / 2;
	q = 6 * m;
	if (q < p) r = p - q;
	else r = q - p;
  
	if (180 < r) r = 360 - r;
  
  r*=3.141592653589/180;
 

	 long double ans;
	ans = sqrt(a * a + b * b - 2 * a * b * cos(r));
	cout << setprecision(10)<< ans << "\n";

	return 0;
}