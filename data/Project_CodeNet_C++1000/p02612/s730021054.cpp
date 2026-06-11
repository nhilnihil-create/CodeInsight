#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
		int n;
		cin >> n;
		if(n % 1000)
			cout << 1000 - (n % 1000) << "\n";
		else
			cout << 0 << "\n";
	return 0;
}