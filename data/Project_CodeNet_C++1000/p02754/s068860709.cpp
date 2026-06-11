#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0);   
	ll n,a[200009],m,k,ans=0,fl=0;
	string s;
	cin>>n>>m>>k;
	ll temp=n/(m+k);
	ll p=min(n%(m+k),m);
	cout<<(temp*m)+p<<endl;
	return 0;
}