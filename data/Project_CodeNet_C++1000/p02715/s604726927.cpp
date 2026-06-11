#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define mt make_tuple
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sqr(x) ((ll)(x) * (x))

const ll mod = 1e9 + 7LL;
const ll MAXK = 1e5 + 1LL;

ll cnt[MAXK];

ll modpow(ll a, ll n)
{
    if(n==0LL)return 1LL;
    ll vrednost = modpow(a,n/2)%mod;
    ll resenje = (vrednost*vrednost)%mod;
    if(n%2==0)
    {
        return resenje;
    }
    else
    {
        return (resenje*a)%mod;
    }
}

int main()
{
    ll n, k;
    cin >> n >> k;

    cnt[k]=1LL;

    ll resenje = k;

    for(ll g = k-1; g >= 1; --g)
    {
        ll kolkoIma=k/g;
        cnt[g]=modpow(kolkoIma, n);

        for(ll i = 2LL * g; i <= k; i += g)
        {
            cnt[g] -= cnt[i];
            if(cnt[g] < 0)
            {
                cnt[g]+=2*mod;
            }
            cnt[g]%=mod;
        }

        resenje = (resenje + (cnt[g]*g)%mod)%mod;
    }

    cout << resenje << '\n';

    return 0;
}
