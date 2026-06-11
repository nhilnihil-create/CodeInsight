#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c;
	cin >> a >> b >> c;
	cout << (c + max(a,b) - 1) / max(a,b) << endl;
	return 0;	
 } 