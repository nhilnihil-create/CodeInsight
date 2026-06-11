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

vector<ll> vratiDelioce(ll n)
{
    vector<ll> v;

    for(ll i = 1LL; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            v.pb(i);

            if(n/i != i)
            {
                v.pb(n/i);
            }
        }
    }

    return v;
}

void debug(vector<ll> &v)
{
    for(auto e : v)cout << e << ' ';
    cout << '\n';
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> prviNiz = vratiDelioce(n-1);
    vector<ll> drugiNiz = vratiDelioce(n);

    //debug(prviNiz);
    //debug(drugiNiz);

    set<int>res;

    for(auto e : prviNiz)
    {
        if(e==1)continue;
        res.insert(e);
    }

    for(auto e : drugiNiz)
    {
        if(e == 1)continue;
        ll vrednost = n;

        while(vrednost % e == 0)
        {
            vrednost /= e;
        }

        if(vrednost % e == 1)
        {
            res.insert(e);
        }
    }

    cout << (int)res.size() << '\n';

    return 0;
}
