#include <iostream>
#include <cstdio>

using namespace std;

void solve()
{
	int a, b;
	cin >> a >> b;
	printf("%d %d %.6f\n", a / b, a % b, (double)a / b);
}

int main()
{
	solve();
	return(0);
}