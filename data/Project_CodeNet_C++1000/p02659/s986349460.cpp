#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	long long a,c;
	double b;
	cin>>a>>b;
//	b=floor(b);
	c=b*100+0.3;
	cout<<(long long)(a*c)/100<<endl;
	return 0;
}
