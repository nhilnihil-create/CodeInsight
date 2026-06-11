#include<bits/stdc++.h>
#include<set>
#define lli long long int
using namespace std;
int main()
{
	lli a,i,b,p,q;
	cin>>a;
	cin>>b;
	p=a;
	q=b;
	for(i=0;i<q-1;i++){
		a=p+a*10;
	}
	for(i=0;i<p-1;i++)
		b=q+b*10;
	if(p>q)
	cout<<b;
	else if(p<q)
	cout<<a;
	else if(p==q)
	cout<<a;	
	return 0;
}