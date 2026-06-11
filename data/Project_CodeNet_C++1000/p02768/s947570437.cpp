#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define p_b push_back
#define pll pair < ll , ll >

using namespace std;

const ll M = 1000000007;

ll mult( ll a, ll b)
{
    return (a*b)%M;
}

ll bin_pow( ll a, ll n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0)
    {
        ll b = bin_pow(a,n/2)%M;
        return mult(b,b);
    }
    else
    {
        return (bin_pow(a,n-1)*a)%M;
    }
}

ll solve( ll a, ll n)
{
    ll p = 1, q = 1;
    for( int i = 1; i <= a; i++)
    {
        p = mult(p,i);
    }
    for( int i = 0; i < a; i++)
    {
        q = mult(q,n-i);
    }
    return mult(q,bin_pow(p,M-2));
}


int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans = bin_pow(2,n)-1;
    ans = ans - solve(a,n)-solve(b,n);
    ans%=M;
    if(ans<0)
    {
        ans+=M;
    }
    cout << ans;
}
