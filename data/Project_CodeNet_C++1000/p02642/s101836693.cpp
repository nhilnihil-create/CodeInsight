#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vpli vector<pair<long long,int>>
#define deb(x) cout<<x<<endl;
#define all(x) x.begin(),x.end()
ll MOD = 1e9+7;
const int M = 1e6+5;
vi sieve(M,0);

int helper()
{
    for(int i=1;i<M;i++)
    {
        if(sieve[i]> 0)
        {
            for(int j=i+i;j<M;j+=i)
            {
                if(sieve[j]>0)
                    sieve[j]++;
            }
        }
    }
    int count = 0;
    for(int i =0;i<M;i++)
    {
        if(sieve[i] == 1) count++;
    }
    return count;
}

void solve()
{
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        sieve[x]++;
    }
    cout<<helper();
}

int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}