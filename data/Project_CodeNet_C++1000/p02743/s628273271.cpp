#include<bits/stdc++.h>
using namespace std;
int main()
{
	long double a, b, c;
	cin >> a >> b >> c;
	if((a + 2*sqrt(a*b) + b) < c) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}