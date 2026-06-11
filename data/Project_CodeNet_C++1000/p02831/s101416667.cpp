#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long a, b;
	cin >> a >> b;
	cout << (a * b) / __gcd(a, b);
	return 0;
}