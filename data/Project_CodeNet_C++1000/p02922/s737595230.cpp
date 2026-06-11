#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, n;
	cin >> a >> b;
	n = (a+b-3)/(a-1);
	cout << n << endl;
	return 0;
}
