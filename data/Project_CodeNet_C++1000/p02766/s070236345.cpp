#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, k, c = 0; cin >> n >> k;
	while(n > 0)
	{
		n /= k;
		c++;
	}
	cout << c << endl;
}

