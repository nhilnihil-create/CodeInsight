#include<iostream>
using namespace std;
int main()
{
		int a,b,k,temp=0;
		cin>>k>>a>>b;
		while (temp<a)
		{
			temp=temp+k;
		}

		if(temp>=a && temp<=b)
		cout<<"OK";
		else 
		cout<<"NG";
}

