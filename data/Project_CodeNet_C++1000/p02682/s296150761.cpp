#include <iostream>
#include <cstdio>
using namespace std;

int n, a, b, c;
int main()
{
	cin >> a >> b >> c >> n;
	if (a >= n) cout << n;
	else if (a + b >= n) cout << a;
	else cout << a - (n - a - b);
    return 0;
}
