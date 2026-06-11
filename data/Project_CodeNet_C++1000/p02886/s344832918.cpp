#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n; cin >> n;
	int d[55];
	for (int i = 0; i < n; ++i)
		cin >> d[i];
	int sum = 0, t = d[0];
	for (int i = 1; i < n; ++i)
	{
		sum += t * d[i]; 
		t += d[i];
	}
	cout << sum << endl;
}

