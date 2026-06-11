#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN
#define itn int
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+1;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

void solve()
{
    vi p(MAXN);
    p[1]=1;
    for (int i=2;i<MAXN;i++)
    {
        if (p[i])
            continue;
        p[i]=i;
        for (ll j=1ll*i*i;j<MAXN;j+=i)
        {
            if (p[j])
                p[j]=min(p[j],i);
            else
                p[j]=i;
        }
    }
    vector <int> cnt(MAXN);
    int n;
    cin>>n;
    vector <int> a(n);
    rep(i,n)
    {
        cin>>a[i];
        int x=a[i];
        while (x>1)
        {
            int y=p[x];
            while (x%y==0)
                cnt[y]++,x/=y;
        }
    }
    bool ok=true;
    for (int i=0;i<n;i++)
    {
        if (!ok)
            break;
        int x=a[i];
        while (x>1)
        {
            int chet=0;
            int y=p[x];
            while (x%y==0)
                chet++,x/=y;
            if (cnt[y]>chet)
            {
                ok=false;
                break;
            }
        }
    }
    if (ok)
    {
        cout<<"pairwise coprime\n";
        return;
    }
    int x=0;
    for (int i=0;i<n;i++)
        x=__gcd(x,a[i]);
    if (x==1)
        cout<<"setwise coprime\n";
    else
        cout<<"not coprime\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
//    cin>>_t;
    _t=1;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}