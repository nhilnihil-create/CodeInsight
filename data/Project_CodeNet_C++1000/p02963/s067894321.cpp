#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
const int maxn=100010;
typedef long long ll;
int main()
{
    ll s;
    scanf("%lld", &s);
	ll a=0,b=0,c=0,d=0;
    a=d=sqrt(s);
    //cout << a << d << endl;
	while(s>a*d)
    {
		if(a < d) a++;
		else d++;
	}
	ll k=a*d-s;
	for(int i=1;i<=sqrt(k);i++)
    {
		if(!(k%i))
        {
			if(i<=1e9&&k/i<=1e9)
            {
				b=i;
				c=k/i;
				break;
			}
		}
	}
	printf("0 0 %lld %lld %lld %lld\n", a, b, c, d);
    return 0;
}