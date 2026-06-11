#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Base
{
	ll d[65];
	const ll mx;

	Base(ll mx = 60) : mx(mx)
	{
        for(ll i = 0; i <= mx; i++)    d[i] = 0;
	}

	void insert(ll x)
	{
	    for(ll i = mx; ~i; --i)
        {
            if(x & (1LL << i))
            {
                if(!d[i])
                {
                    d[i] = x;
                    break;
                }

                x ^= d[i];
            }
        }
	}

	bool Can(ll x, ll j)
	{
	    for(ll i = mx; ~i; --i)
            if(x & (1LL << i))
                x ^= d[i];

        x &= ((1LL << mx) - (1LL << j));

	    return x == 0;
	}
};

ll Get(ll Mask, ll j)
{
    return (Mask & (1LL << j)) ? 1LL : 0LL;
}

int main()
{
    ll n;  cin >> n;

    ll Xor = 0;
    vector <ll> a(n);

    for(ll& x : a)  scanf("%lld", &x), Xor ^= x;

    vector <ll> Even;

    for(ll k = 0; k < 60; k++)
        if(!(Xor & (1LL << k)))
            Even.push_back(k);

    Base B(Even.size());

    for(ll i = 0; i < n; i++)
    {
        ll x = 0;

        for(ll j = 0; j < Even.size(); j++) x ^= (Get(a[i], Even[j]) << j);

        B.insert(x);
    }

    ll Ans = 0;

    for(ll j = (ll) Even.size() - 1, Mask = 0; ~j; --j)
    {
        if(B.Can(Mask | (1LL << j), j))
        {
            Mask |= (1LL << j);
            Ans += 2LL * (1LL << Even[j]);
        }
    }

    cout << Ans + Xor << endl;
}
