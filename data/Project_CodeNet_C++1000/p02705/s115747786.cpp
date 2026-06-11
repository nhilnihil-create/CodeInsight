// Starting with the name of Allah

#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define Nayon ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define gcd(a,b)         __gcd(a,b)
#define lcm(a,b)         (a/gcd(a,b))*b
#define v_sum(a)         accumulate(a.begin(),a.end(),0)
#define v_max(a)         *max_element(a.begin(),a.end())
#define v_min(a)         *min_element(a.begin(),a.end())
#define v_uni(a)         a.erase(unique(a.begin(),a.end()),a.end())
# define pi           3.14159265358979323846

using namespace std;




int main()
{
	Nayon;
	float a,sum=0.0;
	cin>>a;
	sum=2*pi*a;
	printf("%0.20f\n",sum);
	return 0;
}
