#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
using namespace std;
long long a,b,c;
int main()
{
	cin>>a>>b>>c;
	if(c-a-b>0&&4*a*b<sqr(c-a-b))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}