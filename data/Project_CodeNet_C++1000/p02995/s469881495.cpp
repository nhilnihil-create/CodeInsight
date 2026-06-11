#include"bits/stdc++.h"

using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define nl "\n"
#define sp " "
#define int long long
#define PI 3.141592653589793
#define scanstr(s) cin>>ws; getline(cin,s);

int lcm( int a, int b )
{
	int g=__gcd(a,b) ;
	return (a/g)*b ;
}

int len(int a, int b, int d)
{
	int start=a/d;
	if(a%d) start++;
	int stop=b/d;
	return ( stop - start ) + 1 ;
}

void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a>b) swap(a,b);
	int m1 = len(a,b,c);
	int m2 = len(a,b,d);
	int l = lcm(c,d);
	int add = len(a,b,l);
	cout<< (b-a+1)-(m1+m2)+add <<nl;
	return ;
}

int32_t main()
{
	FastIO;
	solve();
	return 0;
}
