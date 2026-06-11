#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200010;
ll a[N],k;
int n;
map<ll,ll> mp;
int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        if(i>=k) mp[(a[i-k]-i+k)%k]--;
        ans+=mp[(a[i]-i)%k]++;
    }
    cout << ans << endl;
    return 0;
}