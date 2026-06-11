#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;
int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll ans1=1,ans2=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans1=i;
            ans2=n/i;
        }
    }
    ll ans3=ans1+ans2-2;
    cout<<ans3<<'\n';


}
