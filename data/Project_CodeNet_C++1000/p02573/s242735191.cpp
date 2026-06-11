#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) ((a+b-1)/(b))
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define dbg(msg, var) cerr << msg << " " << var << endl;

using namespace std;

const int MAX = 200010;
const int MOD = 1000000007;
const int INF = 1e8;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-7;

// End Template //

struct DSU {
    int n;
    vi parent, size;

    DSU(int n) {
        this->n = n;
        parent.assign(n+1, 0);
        size.assign(n+1, 1);

        for(int i=0;i<=n;i++)
            parent[i] = i;
    }

    int find(int v) {
        if(v==parent[v])
            return v;
        return parent[v]=find(parent[v]);
    }

    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if(a!=b) {
            if(size[a]<size[b])
                swap(a, b);

            parent[b]=a;
            size[a]+=size[b];
        }
    }
};

int main()
{sws;

    int n, m, a, b;
    cin >> n >> m;
    DSU dsu(n+1);

    for(int i=0;i<m;i++){
        cin >> a >> b;
        dsu.join(a, b);
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dsu.size[dsu.find(i)]);
    }

    cout << ans << endl;


    return 0;
    
}