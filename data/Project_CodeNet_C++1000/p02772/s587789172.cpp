#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p, a, b) for (ll p = a; p < b; p++)
#define rap(p, a, b) for (ll p = a; p <= b; p++)
#define per(p, a, b) for (ll p = a; p >= b; p--)
#define F first
#define S second
using namespace std;

typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;

int main()
{
    ll t, i, j, k, ans, n;

    //cin>>t;
    t = 1;
    while (t--)
    {
        ll f=1;
        cin>>n;
        vll v(n);
        rep(p,0,n)
        {
            cin>>v[p];
            if(v[p]%2==0)
            {
                if(!(v[p]%3==0 || v[p]%5==0))f=0;
            }
        }

        if(f)cout<<"APPROVED";
        else cout<<"DENIED";
    }

    return 0;
}