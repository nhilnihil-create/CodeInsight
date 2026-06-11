#include<iostream>

using namespace std;
int main()
{
	long long int m1, m2, a, b, c, d;
	cin >> a >> b >> c >> d;
	m1 = max(a*c, a*d);
	m2 = max(b*c, b*d);
	cout << max(m1, m2);
	return 0;
}