#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

int main()
{
	ll s,a,b,c,d;
	cin>>s; cout<<0<<" "<<0<<" ";
	a=1e9; if(s%a==0) b=s/a; else b=s/a+1;
	ll s2=a*b-s; cout<<a<<" "<<1<<" "<<s2<<" "<<b<<endl;
	return 0;
}