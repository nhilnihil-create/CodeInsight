#include<iostream>
using namespace std;

int main()
{
	int a,b,c,d,e,f,g,h;
	cin>>a>>b>>c>>d;
	cin>>e>>f>>g>>h;
	
	int s=a+b+c+d;
	int t=e+f+g+h;
	if(s>t)
	cout<<s<<endl;
	
	else if(s<t)
	cout<<t<<endl;
	
	else if(s==t)
	cout<<s<<endl;
	
	return 0;
}