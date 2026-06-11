#include<bits/stdc++.h>
#define ll long long

 
using namespace std;
int main()
{
    ll n;
    cin>>n;
    if(n&1)
		cout<<0<<"\n";
    else
	{
        ll res=0;
        ll tmp=10;
        while(tmp<=n)
        {
            res+=n/tmp;
            tmp*=5;
        }
        cout<<res<<"\n";
    }
}