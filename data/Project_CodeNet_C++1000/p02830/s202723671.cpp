#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(z) (z).begin(),(z).end() 
#define MOD 1000000007
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll isprime(ll n)
{
	for(int i=2;i<n;i++)
		if(n%i==0)
		return 0;
		
	return 1;	
}
int main()
{ 
    FAST;
    ll n;
    cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	string s3="";
	for(int i=0;i<n;i++)
	{
		s3+=s1[i];
		s3+=s2[i];
	}
	cout<<s3;
}
