#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	switch (n%10)
	{
		case 3: cout << "bon" << endl; break;

		case 0:
		case 1:
		case 6:
		case 8: cout << "pon" << endl; break;
		default: cout << "hon" << endl; break;
	}
}

