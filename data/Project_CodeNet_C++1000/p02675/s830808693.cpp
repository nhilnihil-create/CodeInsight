#include<bits/stdc++.h>
#define ll long long

const ll mod = 1000000007 ;

bool isInteger(double n)
{
	if(floor(n)==ceil(n))
		return true ;
	return false ;
}

using namespace std ;

int main()
{
	int n;
	cin>>n;
	int x = n%10 ;
	if(x==2 || x==4 || x==5 || x==7 || x==9)
		cout<<"hon";
	else if(x==0 || x==1 || x==6 || x==8)
		cout<<"pon";
	else 
		cout<<"bon";
}
