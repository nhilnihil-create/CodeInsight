#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	n--;
	int c = 0;
	for (int a = 1; a <= n; ++a)
		c += n/a;
	cout << c << endl;
}
