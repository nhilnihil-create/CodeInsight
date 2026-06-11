#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long

#define for(i,a,b) for (i=a; i<b; i++)
#define forb(i,a,b) for (i=a; i>b; i--)
#define all(S) S.begin(),S.end()
#define sort(S) sort(all(S))

const int inf = 1e9+7;
const ll INF = 1e18;
const int sq = 320;

ll m[200000],r;
vector <pair <ll,ll> > V;

ll st(ll a, ll b)
{
    ll ans = 1;
    ll a1 = a;
    int i;
    for (i,0,17)
    {
        if (b&(1<<i))
            ans=(ans*a1)%inf;
        a1=(a1*a1)%inf;
    }
    return ans;
}

void go(ll k, ll ans)
{
    if (k==V.size())
    {
        r-=m[ans];
        return;
    }
    ll bns = ans;
    ll i;
    go(k+1,ans);
    for (i,0,V[k].s)
    {
        bns*=V[k].f;
        go(k+1,bns);
    }
    return;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n,k,ans=0,i,j;
    cin >> n >> k;
    for (i,1,k+1)
    {
        ll kol = k/i;
        r = i;
        V.clear();
        ll u = i;
        for (j,2,sq)
            if (i%j==0)
        {
            V.pb(mp(j,0));
            while (u%j==0)
            {
                V.back().s++;
                u/=j;
            }
        }
        if (u>1)
            V.pb(mp(u,1));
        go(0,1);
        m[i]=r;
        ans=(ans+st(kol,n)*r)%inf;
    }
    cout << (ans+inf)%inf << endl;
}
