#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL mo=1e9+7;
LL power(LL a,LL b)
{
	LL cnt=1;
	while(b)
	{
		if(b&1)
		{
			cnt*=a;
			cnt%=mo;
		}
		a*=a;
		a%=mo;
		b>>=1;
	}
	return cnt;
}
LL solve(LL a)
{
	return ((power(10,a)+mo-power(9,a))%mo-(power(9,a)+mo-power(8,a))%mo+mo)%mo;
}
int main()
{
	LL a;
	cin >> a;
	cout << solve(a);
}