#include<bits/stdc++.h>
#define ll long long
using namespace std;
int arr[10000001];
int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j+=i) arr[j]++;
    }
    ll sum=0;
    for(ll i=1;i<=n;i++) sum+=i*arr[i];
    cout<<sum<<endl;
    return 0;
}
