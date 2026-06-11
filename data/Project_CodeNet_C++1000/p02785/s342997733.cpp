#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n,k,i,sum=0;
    cin>>n>>k;
    ll a[n];
    for(i=0;i<n;i++) cin>>a[i];
    if(k>=n)
    {
        cout<<"0";
    }
    else
    {
        sort(a,a+n,greater<int>());
        for(i=k;i<n;i++)
        {
            sum+=a[i];
        }
        cout<<sum;
    }
    return 0;
}