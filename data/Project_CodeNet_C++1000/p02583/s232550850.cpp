#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
        cin>>arr[i];
        ll cnt=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            for(ll k=j+1;k<n;k++)
            {

                ll a = arr[i];
                ll b = arr[j];
                ll c = arr[k];
                if(a!=b&&b!=c&&a!=c)
                {
                        if(a+b>c&&b+c>a&&a+c>b)
                            cnt++;
                }

            }
        }
    }
    cout<<cnt<<endl;
}

