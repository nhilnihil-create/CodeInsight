#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a,b,c,d,ac,ad,bc,bd;
	cin>>a>>b>>c>>d;
	ac=a*c;
	ad=a*d;
	bc=b*c;
	bd=b*d;
	cout<<(ac>(ad>(bc>bd?bc:bd)?ad:(bc>bd?bc:bd))?ac:(ad>(bc>bd?bc:bd)?ad:(bc>bd?bc:bd)));
	return 0;
}