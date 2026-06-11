#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c,d;
	cin >> a >> b >> c >> d;
	long long p=a*c, q=a*d, r=b*c, s=b*d;
	cout << max(max(max(p,q), r), s);
	return 0;
}