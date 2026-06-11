
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define pii pair<int, int>
#define vpli vector<pair<long long, int>>
#define deb(x) cout << "deb " << #x << " " << x << endl
#define all(x) x.begin(), x.end()
#define endl "\n"

const int M = 998244353, N = 2e5 + 3;
vll fact(N), inv_fact(N);

ll bpow(ll base, int exp)
{
    if (exp == 0)
        return 1ll;
    ll ans = bpow(base, exp / 2);
    ans = (ans * ans) % M;
    if (exp % 2)
        ans = (ans * base) % M;
    return ans;
}
void pre()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % M;
    inv_fact[N-1] = bpow(fact[N-1],M-2);
    for(int i=N-2;i>=0;i--)
    {
        inv_fact[i] = ((i+1)*inv_fact[i+1])%M;
    }
}
inline ll ncr(int n, int r)
{
    return (((inv_fact[r]*inv_fact[n-r])%M)*fact[n])%M;
}
void print(vll v,int n)
{
    cout<<"DEBUG\n";
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void solve()
{
    ll x;
    cin>>x;
    for(ll a = -1000;a<=1000;a++)
    {
        for(ll b = -1000;b<=1000;b++)
        {
            if((a*a*a*a*a)-(b*b*b*b*b) == x)
            {
                cout<<a<<" "<<b<<endl;
                return;
            }
        }
    }
}

int main()
{
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}