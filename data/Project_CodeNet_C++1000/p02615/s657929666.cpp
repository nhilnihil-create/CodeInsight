#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define ld long double
#define pii 3.14
#define mod (ll)(1e9+7)
#define inf (ll)(1e18)
#define lim (ll)(1e10)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define pi pair<int,int>
#define N (ll)(2e5 + 5)

void solve()
{
    ll n;
    cin>>n;

    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    ll ans = arr[n-1];
    ll ptr = n-2;
    for(int i=n-3;i>=0;i-=2)
    {
        if(i == 0)
            ans += arr[ptr--];
        else
            ans += 2*arr[ptr--];
    }

    cout<<ans;
}

int main()
{
    fio;
    ll tc = 1;
    //cin>>tc;
    while(tc--)
    {
        solve();
    }
}
