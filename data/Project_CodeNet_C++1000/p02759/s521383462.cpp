#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll ans=n/2;
    if(n%2) ans++;
    cout<<ans;
}