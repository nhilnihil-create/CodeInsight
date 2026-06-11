#include <bits/stdc++.h>
     
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int t1, t2;
	long long int a1, a2, b1, b2;

	cin >> t1 >> t2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;

	long long int d1 = (a1 - b1)*t1;
	long long int d2 = (a2 - b2)*t2;
	if(d1>0)
	{
 		d1 = -1*d1;
 		d2 = -1*d2;
	}

	if(d1+d2<0)
	{
		cout << 0 << '\n';
		return 0;
	}
	else if(d1+d2==0)
	{
		cout << "infinity" << '\n';
		return 0;
	}

	long long int res = -d1/(d1+d2);
	if((-d1)%(d1+d2)==0)
	{
		cout << 2*res << '\n';
	}
	else
	{
		cout << 2*res+1 << '\n';
	}
	
	return 0;
}
