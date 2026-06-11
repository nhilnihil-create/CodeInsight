#include<bits/stdc++.h>

using namespace std;

#define N 1000005

int n, a[N];

string s;

int get()
{
	int res = 0;
	for(int i = 0; i <= n; i++)
	{
		int now = a[i] % 2;
		if(now && ((n & i) == i)) res ^= 1;
	}
	return res;
}

int main()
{
	cin >> n >> s;
	n--;
	for(int i = 0; i <= n; i++)
		a[i] = s[i] - '1';
	if(get()) cout << 1 << endl;
	else
	{
		for(int i = 0; i <= n; i++)
			if(a[i] == 1) 
			{
				cout << 0 << endl;
				return 0;
			}
		for(int i = 0; i <= n; i++)
			a[i] /= 2;
		if(get()) cout << 2 << endl;
		else cout << 0 << endl;
	}
	return 0;
}