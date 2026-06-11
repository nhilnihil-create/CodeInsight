#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y;
	x = (c - c % b) / b;
	y = (a - a % d) / d;
	if (c % b != 0) x++;
	if (a % d != 0) y++;


	if (x <= y) cout << "Yes" << "\n";
	else cout << "No" << "\n";


	return 0;
}