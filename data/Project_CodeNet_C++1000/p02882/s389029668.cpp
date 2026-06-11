#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;
const double pi = acos(-1);

int main()
{
	double a,b,x;
	cin >> a >> b >> x;
	x /= a;
	if(a*b>=x*2.0)
	{
		printf("%.10lf\n",atan2(b,x/b*2)*180/acos(-1));
	}
	else
	{
		double c = 2.0*x/a-b;
		printf("%.10lf\n",atan2(b-c,a)*180.0/pi);
	}

}
