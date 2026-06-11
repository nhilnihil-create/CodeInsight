#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vll vector<long long>
#define pll pair<long long, long long>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1e18

typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> o_tree;

// if we convert that bound day to x ,then person cant work for k days in any possilbe way
// bound day is o

void solve()
{
    ll n, k, c;
    cin >> n >> k >> c;
    ll i, j;
    string s;
    cin >> s;
    ll a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = (s[i] == 'o');
    }
    ll next_work[n];
    ll prev_work[n];
    memset(next_work, -1, sizeof(next_work));
    memset(prev_work, -1, sizeof(prev_work));
    next_work[n - 1] = (a[n-1] ? n - 1 : -1);
    prev_work[0] = (a[0])? 0:-1;
    for(i=1;i<n;i++)
    {
        if (a[i])
        {
            prev_work[i] = i;
        }
        else
        {
            prev_work[i] = prev_work[i - 1];
        }
    }
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i])
        {
            next_work[i] = i;
        }
        else
        {
            next_work[i] = next_work[i + 1];
        }
    }
    ll days=0;
    for(i=0;i<n;i)
    {
        ll nowday = next_work[i];
        if(nowday==-1)break;
        days++;
        i=nowday+c+1; 
    }
    if(days>k)
    {
        return;
    }
    // cout<<"Yet\n";
    // in these cases only max k days of work is possible
    
    ll l[k],r[k];
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    days=0;
    for(i=0;i<n;)
    {
        ll nowday = next_work[i];
        l[days++]=nowday;
        i=nowday+c+1;
    }
    days=0;
    for(i=n-1;i>=0;)
    {
        ll nowday = prev_work[i];
        r[days++]=nowday;
        i=nowday-c-1;
    }
    reverse(r,r+k);
    for(i=0;i<k;i++)
    {
        // cout<<l[i]<<" "<<r[i]<<"\n";
        if(l[i]==r[i])
        {
            cout<<l[i]+1<<"\n";
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    cout << setprecision(20);

    ll t = 1;

    // cin>>t;

    while (t--)
    {
        solve();
    }

    return 0;
}