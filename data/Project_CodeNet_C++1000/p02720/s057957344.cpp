 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define pb push_back
#define ff first
#define ss second
#define SIZE 200001
#define INF int(2e9 + 9)
#define BIG_INF 1e18 + 9
#define acmpIN "input.txt"
#define acmpOUT "output.txt"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

//#pragma GCC optimize("Ofast")

ll n, a[SIZE], b[SIZE], c[SIZE];

vector<int> g[SIZE];


ll Ans = 0;

pii dfs(int u, int p, ll mn)
{
    pii cur = {0, 0};
    if(b[u] != c[u])
    {
        if(b[u]) cur.ff++;
        else cur.ss++;
    }

    for(int v: g[u])
    {
        if(v == p) continue;
        pii given = dfs(v, u, min(mn, a[u]));
        cur.ff += given.ff;
        cur.ss += given.ss;
    }

    if(a[u] < mn)
    {
        ll kol = min(cur.ff, cur.ss);
        Ans += 2 * kol * a[u];
        cur.ff -= kol;
        cur.ss -= kol;
    }
    return cur;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen(acmpIN, "r", stdin);
//    freopen(acmpOUT, "w", stdout);

    cin >> n;


    queue<ll> q;
    for(int i = 1; i <= 9; i++)
    {
        q.push(i);
    }
    ll top = 0;
    while(n--)
    {
        top = q.front();
        q.pop();
        if(top % 10 != 0)
        {
            q.push(top * 10 + top % 10 - 1);
        }
        q.push(top * 10 + top % 10);
        if(top % 10 != 9)
        {
            q.push(top * 10 + top % 10 + 1);
        }
    }

    cout << top;
    return 0;
}

