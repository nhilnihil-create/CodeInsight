#include <bits/stdc++.h>
#define N 1000000007
using namespace std;
int main()
{
	long long n;
	long long a=1,b=1,c=1;
	cin >> n;
	for(long long i=1; i<=n; i++)
	{
		a = a % N * 10 % N;
		b = b % N * 9 % N;
		c = c % N * 8 % N;
	}
	cout << (((a % N + c % N) % N + N - b) % N + N - b) % N << endl;
}