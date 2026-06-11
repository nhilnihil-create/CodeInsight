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

bool fn(string arr[],int n,int m,int k,int r,int c)
{
    set<int> rr,cc;

    int x=r, y=c ,i=0;

    while(x)
    {
        if(x&1)
            rr.insert(i);
        x>>=1;
        i++;
    }

    i = 0;
    while(y)
    {
        if(y&1)
            cc.insert(i);
        y>>=1;
        i++;
    }

    int cnt = 0;
    for(i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == '#' && rr.find(i)==rr.end() && cc.find(j)==cc.end())    cnt++;

        }
    }

    return (cnt == k);

}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;

    string arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int ln = (1<<n) , lm = (1<<m),ans = 0;
    for(int i=0;i<ln;i++)
    {
        for(int j=0;j<lm;j++)
        {
            if(fn(arr,n,m,k,i,j))
                ans++;
        }
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
