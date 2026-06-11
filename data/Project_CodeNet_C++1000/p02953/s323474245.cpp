// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define N 100005
#define mod 1000000007

int main()
{   
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    ll cnt=0;
    for(ll i=n-1;i>0;i--)
    {
        if(a[i-1]<=a[i])
        continue;
        if((a[i-1]-1)>a[i])
        {
            cnt=1;break;
        }
        else
        a[i-1]-=1;
    }
    if(cnt)
    cout<<"No"<<"\n";
    else
    cout<<"Yes"<<"\n";
    return 0;
}