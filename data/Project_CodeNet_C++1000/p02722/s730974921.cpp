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

const int inf = 1e9;
const ll INF = 1e18;

const ll r = 1e6+1;

ll n,k=0;
vector <pair <ll,int> > V;

void go(ll m, int q)
{
    if (q==V.size())
    {
        //cout << m << endl;
        if (m==1)
            return;
        ll n1 = n;
        while (n1%m==0)
        n1/=m;
        if (n1%m==1)
            k++;
        return;
    }
    ll p = m;
    int i;
    for (i,0,V[q].s+1)
    {
        go(p,q+1);
        p*=V[q].f;
    }
    return;
}

void go1(ll m, int q)
{
    if (q==V.size())
    {
        //cout << m << endl;
        if (m>1)
        k++;
        return;
    }
    ll p = m;
    int i;
    for (i,0,V[q].s+1)
    {
        go1(p,q+1);
        p*=V[q].f;
    }
    return;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll i;
    cin >> n;
    ll m = n;
    for (i,2,r)
        if (m%i==0)
    {
        int q = 0;
        while (m%i==0)
        {
            m/=i;
            q++;
        }
        V.pb(mp(i,q));
    }
    if (m>1)
        V.pb(mp(m,1));
    go(1,0);
    V.clear();

    m = n-1;
    for (i,2,r)
        if (m%i==0)
    {
        int q = 0;
        while (m%i==0)
        {
            m/=i;
            q++;
        }
        V.pb(mp(i,q));
    }
    if (m>1)
        V.pb(mp(m,1));
    go1(1,0);
    cout << k << endl;
    return 0;
}
