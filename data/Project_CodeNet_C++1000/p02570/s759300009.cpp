#include<iostream>
using namespace std;

int main()
{
	int d,t,s;
	cin>>d>>t>>s;

	float d1,t1,s1,req;

	req=(float)d/(float)t;
	float req1=(float)s;
	if(req<=req1)
		cout<<"Yes"<<endl;
	else 
		cout<<"No"<<endl;

	return 0;

}