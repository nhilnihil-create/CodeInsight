#include<iostream>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b>>c;
	int s=a+b+c;
	if(s>=22) cout<<"bust";
	else cout<<"win";
	return 0;
}