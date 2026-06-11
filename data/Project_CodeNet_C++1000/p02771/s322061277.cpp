#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if((a==b&&c!=a)||(a==c&&b!=a)||(b==c&&a!=b)){
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}