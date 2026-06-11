#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 1e9;
ll x1,x2,x3,y4,y2,y3;
ll s;
int main()
{
	cin >> s;
	x2=y2=0;
	x1=y3=sqrt(s);
	while(s>x1*y3)
	{
		if(x1<y3)	x1++;
		else y3++;
	}
	ll m = x1*y3-s;
	for(int i=1;i<=sqrt(m);i++)
	{
		if(m%i==0)
		{
			if(i<=MAX&&m/i<=MAX)
			{
				y4=i;
				x3=m/i;
				break;
			}
		}
	}
	cout << x1<<" "<<y4<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
	
	
	
	return 0;
}