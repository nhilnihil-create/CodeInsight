#include <bits/stdc++.h>
using namespace std;
int x,y;
long long a,b,c,d;
long long maxn = -1100000000000000000;
int main()
{
	cin >> a >> b >> c >> d;
	if(a * c > maxn)
		maxn = a * c;
	if(a * d > maxn)
		maxn = a * d;
	if(b * c > maxn)
		maxn = b * c;
	if(b * d > maxn)
		maxn = b * d;
	cout << maxn << endl;
}