#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define set_bits(a) __builtin_popcount(a)
#define pb push_back
#define pf push_front
#define mod 1000000007
#define M 998244353
#define fi first
#define se second
#define endl '\n'
#define INF 1e18
#define PI 3.14159265358979323846
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    
    freopen("output.txt", "w", stdout);
    #endif

    ll n,i;
    cin>>n;
    ll arr[n];
    ll ans=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i%2==0 && arr[i]%2!=0)
        {
            ans++;
        }
    }
    cout<<ans;
}