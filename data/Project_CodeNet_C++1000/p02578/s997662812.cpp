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
    ll n;
    cin>>n;
    ll arr[n];
    cin>>arr[0];
    ll ans = 0;
    f(i,1,n)
    {
        cin>>arr[i];
        if(arr[i]<arr[i - 1])
        {
            ans += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    cout<<ans<<endl;
}
