#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;
vector<ll> val;
ll cnt = 0;
void solve()
{
    
}
bool compare(vector<ll> &a, vector<ll> &b, ll n)
{
    ll i= 0;
    while(i<n)
    {
        if(a[i]!=b[i])
            return false;
        i++;
    }
    return true;
}
bool find(ll k, vector<ll> & ans)
{
    for (ll i = 0; i < ans.size(); i++)
    {
        if(ans[i] == k)
            return true;
    }
    return false;
}
void permute(ll s, vector<ll> &p, vector<ll>& q, ll n, vector<ll> & ans)
{
    // cout<<s<<'\n';
    if(ans.size() == n)
    {
        cnt++;
        // for(ll i=0; i<n; i++)
        // {
        //     cout<<ans[i]<<" ";
        // }
        // cout<<'\n';
        if(compare(ans, p, n))
        {
            val.push_back(cnt);
        }
        if(compare(ans, q, n))
        {
            val.push_back(cnt);
        }
    }
    for(ll i=1; i<=n; i++)
    {
        if(!find(i, ans))
        {
            ans.push_back(i);
            permute(i, p, q, n, ans);
            ans.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
    ll n;
    cin>>n;
    vector<ll> p,q;
    for (ll i = 0; i < n; i++)
    {
        /* code */
        ll p1;
        cin>>p1;
        p.push_back(p1);
    }
    for (ll i = 0; i < n; i++)
    {
        /* code */
        ll p1;
        cin>>p1;
        q.push_back(p1);
    }
    vector<ll> ans;
    for(ll i=1; i<=n; i++)
    {
        ans.push_back(i);
        permute(i, p , q, n, ans);
        ans.pop_back();
    }
    cout<<val[1] - val[0]<<'\n';
}