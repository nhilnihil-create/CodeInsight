#include<bits/stdc++.h>
#define ll long long

const ll mod = 1000000007 ;

using namespace std ;

int main()
{
	string s;
	cin>>s;
	vector<int> v;
	int count = 0 ;
	for(int i=0 ; i<s.length() ; i++)
	{
		if(s[i]=='R' && s[i+1]!='S')
			count++ ;
		else if(s[i]=='R' && s[i+1]=='S')
		{
			v.push_back(count+1);
			count = 0 ;
		}
	}
	v.push_back(count);
	int maxi = *max_element(v.begin(),v.end());
	cout<<maxi;
}
