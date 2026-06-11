#include<iostream>
using namespace std;
int s[]={0,0,31,60,91,121,152,182,213,244,274,305,335},a,b;
string t[]={"Wednesday","Thursday","Friday","Saturday","Sunday","Monday","Tuesday"};
main()
{
	while(cin>>a>>b,a)cout<<t[(s[a]+b)%7]<<endl;
}
