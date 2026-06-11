#include<bits/stdc++.h>
using namespace std;

int main() {
	int x; cin >> x;
	int res = 1;
	while (x * res % 360 != 0)
	{
		res++;
	}
	cout << res << endl;
	return 0;
}
