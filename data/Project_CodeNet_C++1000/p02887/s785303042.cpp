#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define t ll t;cin>>t;while(t--)
#define nn cout<<endl;
int main()
{
	ll n; cin>>n;
	string s;
	cin>>s;
	ll mv=1;
	for(ll i=1;i<n;i++)
	{
		if(s[i]!=s[i-1]) mv++;
	}
	cout<<mv<<endl;
	
}