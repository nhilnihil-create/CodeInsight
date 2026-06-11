//#define _GLIBCXX_DEBUG
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
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vector <ll> b;
int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        vector <ll> a(n);
        rep(i,n)
        cin>>a[i];
        b=vector <ll>(62,-1);
        string s;
        cin>>s;
      //  cout<<s<<'\n';
        bool ok=false;
        for (int i=n-1;i>=0;i--)
        {
            if (ok)
                break;
            for (ll j=0;j<62;j++)
            {
                if ((((a[i])>>j)&1ll)==0)
                    continue;
                if (b[j]!=-1)
                    a[i]^=b[j];
                else
                {
                    b[j]=a[i];
                    if (s[i]=='1')
                    {
                        ok=true;
                    }
                    break;
                }
            }
        }
        if (ok)
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }



    //n=1 ?
    //recursion - matrix exponential
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
}