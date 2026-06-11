//B Ed 31
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int a,b,c,d,e=0;
	cin>>a>>b>>c>>d;
	a--;

	int p= b-a;
	int q= b/c -a/c;
	int r= b/d -a/d;
	int s= (c*d)/ __gcd(c,d);
	int t= b/s - a/s;
	cout<<(p-q-r+t);
}