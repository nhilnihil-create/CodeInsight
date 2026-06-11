#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define nout(ans) cout << (ans) << "\n"
#define sout(ans) cout << (ans) << " "
using namespace std;

const double pi = 3.14159265359;
const ll INF = 1e12;
const ll MOD = 1e9 + 7;
const ll N = 2e5+5; 
/*
Decimal Places: cout << fixed << setprecision(n) << ans << endl
*/

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

ll raise(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


int n, q, parent[N], sz[N]; 

int get(int v) {
    if (v==parent[v]) return v;
    return parent[v] = get(parent[v]);
}

void solve()
{
    cin >> n >> q;
    for (int i=1; i<=n; ++i) parent[i]=i, sz[i]=1;
    while (q--) {
        int temp, a, b; cin >> temp >> a >> b;
        if (temp==0) {
            function<void(int,int)> unite = [&](int a, int b) {
                a=get(a);
                b=get(b);
                if (a!=b) {
                    if (sz[a]<sz[b]) swap(a,b);
                    sz[a]+=sz[b];
                    parent[b]=a;
                }
            };

            unite(a,b);
        }else{
            nout(get(a)==get(b)?1:0);
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++)
    {
        solve();
    }
    return 0;
}