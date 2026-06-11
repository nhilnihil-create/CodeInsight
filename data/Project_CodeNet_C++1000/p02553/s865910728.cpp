#include<iostream>
#include<algorithm>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
typedef long long ll;
ll a,b,c,d;

int main()
{
	ios;
	cin>>a>>b>>c>>d;
	ll m1,m2,m3,m4,maxn;
	m1=a*c,m2=a*d;
	m3=b*c,m4=b*d;
	maxn=max(max(max(m1,m2),m3),m4);
	cout<<maxn<<"\n";
	return 0;
}