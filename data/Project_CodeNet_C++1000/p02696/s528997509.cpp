#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define ll long long
#define pb push_back
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug cout<<"Debugging.."<<endl
using namespace std;
int main()
{
	faster;

	ll int a,b,n;
	cin>>a>>b>>n;
	ll int x=min(b-1,n);
	
	ll int val=floor(a*x/b);
	cout<<val;
}


