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
	int n,d;
	cin>>n>>d;
	vector<int> v[2];
	for(int i=0 ; i<n ; i++)
	{
		int x,y ;
		cin>>x>>y;
		v[0].push_back(x);
		v[1].push_back(y);
	}
	int count = 0 ;
	for(int i=0 ; i<n ; i++)
	{
		if(sqrt((ll)((ll)v[0][i]*v[0][i]+(ll)v[1][i]*v[1][i]))<=d)
			count++ ;
	}
	cout<<count;
}
