#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,k;
 	cin>>n>>k;
 	if(n>=k && k!=1) cout<<n-k;
    else if(n>=k && k==1) cout<<0;
  	else cout<<1;
}
