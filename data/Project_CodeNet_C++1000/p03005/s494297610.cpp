#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	int kai = 0;
	if(k > 1)
	{
		kai = n - k;
	}
	cout << kai << endl;
	return 0;
}
