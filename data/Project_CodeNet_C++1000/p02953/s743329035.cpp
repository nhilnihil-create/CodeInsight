#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i+=1)
    {
        cin >> arr[i];
    }
    for(ll i=1;i<=n-1;i++)
    {
        if(arr[i]>arr[i-1])
        {
            arr[i]--;
        }
        
    }
    ll flag=1;
    for(ll i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            flag=-1;
        }
    }
    if(flag==-1)
    {
        cout << "No\n";
    }
    else
    {
        cout <<"Yes\n";
    }

}
