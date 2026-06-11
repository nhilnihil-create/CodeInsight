#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long int a,b,c,d,p,q,r,s;
	cin>>a>>b>>c>>d;

	p = a*c;
	q = a*d;
	r = b*c;
	s = b*d;

	cout<< max(p,max(max(r,s),q)) <<endl;

	return 0;
}