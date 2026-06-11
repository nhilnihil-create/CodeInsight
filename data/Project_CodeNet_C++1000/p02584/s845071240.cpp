#include <bits/stdc++.h>
#include <limits>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fi(i, n) for( int i=0 ; i<n ; i++ )
#define f(i, a, b) for( int i=a ; i<b ; i++ )
#define vi vector<int>
#define pb push_back
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
ll fact(ll n)
{
    ll ans = 1e14;
    for(ll i = 1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            ll sol = (i - 1) + (n/i - 1);
            ans = min(ans,sol);
        }
    }
    return ans;
}
int visited[200000] = {0};
vector<vector<int> > v(200000);
int dfs(int x)
{
    int ans = 0;
    if(visited[x]==0)
    {
        visited[x] = 1;
        ans++;
        int a = v[x].size();
        for(int j = 0;j<a;j++)
        {
            int data = v[x][j];
            ans = ans + dfs(data);
        }
    }
    return ans;
}
int main()
{
    ll x,k,d;
    cin>>x>>k>>d;
    if(x==0)
    {
        if(k%2==0)
        {
            cout<<x;
        }
        else
        {
            ll y = abs(x - d);
            ll z = abs(x + d);
            cout<<min(y,z)<<endl;
        }
    }
    x = abs(x);
    if((x/k) >= d)
    {
        x = x - k*d;
        cout<<x<<endl;
    }
    else if(x>0)
    {

        while(x>=0 && k>0)
        {
            if(x - d>=0)
            {
                x = x - d;
                k--;
            }
            else
            {
                break;
            }

        }
        if(k==0)
        {
            cout<<x<<endl;
        }
        else
        {
            if(k%2==0)
                cout<<x<<endl;
            else
            {
                ll y = abs(x - d);
                ll z = abs(x + d);
                cout<<min(y,z)<<endl;
            }
        }
    }

}
