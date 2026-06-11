#include<bits/stdc++.h>
#define ll long long

const ll mod = 1000000007 ;

using namespace std ;

int main()
{
	string n;
	cin>>n;
	int sum = 0 ;
	for(int i=0 ;i<n.length() ; i++)
	{
		sum+=(n[i]-(int)'0');
	}
	if(sum%9==0)
		cout<<"Yes"<<"\n";
	else
		cout<<"No"<<"\n";
}
