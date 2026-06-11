#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<int>v;
    vector<int> number(n, -1);
	while (m--)
	{
		int s, c;
		cin>>s>>c;
		if (number[s-1]!=-1 && number[s - 1] != c) //checking for contradiction
		{
			cout<<"-1"<<endl;
			return 0;
		}
		number[s - 1] = c;
	}
	if (number[0]==0 && n!=1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	else
	{
		if(number[0] == -1) number[0]=(n>1);
		for(auto digit : number) 
		    cout<<max(digit,0);
	    cout<<endl;
	}
    return 0;
}