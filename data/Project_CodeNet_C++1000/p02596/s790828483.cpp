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
	int k;
	cin>>k;
	int A[k];
	A[0]=7%k;
	int flag = 0 ;
	for(int i=1 ; i<k ; i++)
	{
		A[i] = (A[i-1]*10+7)%k ;
	}
	for(int i=0 ; i<k ; i++)
	{
		if(A[i]==0)
		{
			cout<<(i+1);
			flag =1;
			break ;
		}
	}
	if(flag==0)
		cout<<-1;

}
