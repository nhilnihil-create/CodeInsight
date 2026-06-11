#include <bits/stdc++.h>
#define N 1000000007
using namespace std;
int f[1100000];
int n;
int main()
{
	cin >> n;
	f[1] = f[2] = 0;
	f[3] = f[4] = f[5] = 1;
	f[6] = 2;
	for(int i=7; i<=n; i++)
		f[i] = (f[i - 1] % N + f[i - 3] % N) % N;
	cout << f[n] % N << endl;
}