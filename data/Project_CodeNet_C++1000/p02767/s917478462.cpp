#include <bits/stdc++.h>
#define mod 1000000007
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)
#define nui 100
#define INF 100000000000
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf int t;cin>>t;for(int w=1;w<=t;w++)
#define pfn cout<<"-1\n"
#define pfp cout<<"1\n";



using namespace std;


ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

ll fermat_inv(ll y) {return binpow(y, mod - 2);}



int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);



    /*ll n, x;
    cin >> n >> x;
    ll a[n];
    F(i, 0, n)
    {
        cin >> a[i];
    }
    ll ans = 0;
    F(i, 0, n)
    {
        if (i - 1 >= 0)
        {
            if (a[i] + a[i - 1] > x)
            {
                if (a[i] >= a[i - 1])
                {
                    ans += a[i] + a[i - 1] - x;
                    a[i] -= a[i] + a[i - 1] - x;

                }
                else
                {
                    ans += a[i] + a[i - 1] - x;
                    a[i] -= a[i] + a[i - 1] - x;

                }
            }
        }
        if (i + 1 < n)
        {
            if (a[i] + a[i + 1] > x)
            {
                if (a[i] > a[i + 1])
                {
                    ans += a[i] + a[i + 1] - x;
                    a[i+1] -= a[i] + a[i + 1] - x;

                }
                else if (a[i] == a[i + 1])
                {
                    ans += a[i] + a[i + 1] - x;
                    a[i + 1] -= a[i] + a[i + 1] - x;
                }
                else
                {
                    ans += a[i + 1] + a[i] - x;
                    a[i + 1] -= a[i] + a[i + 1] - x;

                }
            }
        }
    }
    cout << ans << "\n";*/
    ll n;
    cin >> n;
    ll a[n];
    ll l = 1000;
    ll r = 0;
    F(i, 0, n)
    {
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    ll cost = INF;
    F(i, l, r+1)
    {
        ll k = 0;
        F(j, 0, n)
        {
            k += (a[j] - i) * (a[j] - i);
        }
        cost = min(cost, k);
    }
    cout << cost << "\n";
    return 0;

}