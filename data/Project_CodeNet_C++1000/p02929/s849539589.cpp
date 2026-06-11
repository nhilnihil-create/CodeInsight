#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
const ll MOD = 1000000007;
const ll nmax = 8;
const ll INF = 1e9;
bool graph[nmax][nmax];
vector<vector<ll>> dist = vector<vector<ll>>(nmax, vector<ll>(nmax, INF));
void warshall_floyd(ll n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}

class UnionFind
{
public:
    vector<ll> Parent;

    UnionFind(ll N)
    {
        Parent = vector<ll>(N, -1);
    }
    ll find(ll A)
    {
        if (Parent[A] < 0)
            return A;
        return Parent[A] = find(Parent[A]);
    }

    ll size(ll A)
    {
        return -Parent[find(A)];
    }

    bool Union(ll A, ll B)
    {
        A = find(A);
        B = find(B);
        if (A == B)
        {
            return false;
        }
        if (size(A) < size(B))
            swap(A, B);

        Parent[A] += Parent[B];
        Parent[B] = A;

        return true;
    }
};

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a / g * b;
}

ll mulMod(ll a, ll b)
{
    return (((a % MOD) * (b % MOD)) % MOD);
}

ll powMod(ll a, ll p)
{
    if (p == 0)
    {
        return 1;
    }
    else if (p % 2 == 0)
    {
        ll half = powMod(a, p / 2);
        return mulMod(half, half);
    }
    else
    {
        return mulMod(powMod(a, p - 1), a);
    }
}

ll ceil(ll a, ll b)
{
    return (a + b - 1) / b;
}

void solve(long long N, std::string S)
{
    if (S[0] == 'W' || S[2 * N - 1] == 'W')
    {
        cout << 0 << endl;
        return;
    }

    vector<int> LR(S.size());
    LR[0] = 1;
    int cntL = 1;
    int cntR = 0;
    for (int i = 1; i < S.size(); i++)
    {
        if (S[i - 1] == S[i])
        {
            if (LR[i - 1] == 0)
            {
                LR[i] = 1;
            }
            else
            {
                LR[i] = 0;
            }
            cntL++;
        }
        else
        {
            LR[i] = LR[i - 1];
            cntR++;
        }
    }
    // if(cntL != cntR){
    //     cout << 0 << endl;
    //     return;
    // }
    int L = 0;
    int R = 0;
    ll ans = 1;
    for (int i = 0; i < S.size(); i++)
    {
        if (LR[i] == 1)
        {
            L++;
        }
        else
        {
            ans *= L - R;
            ans %= MOD;
            R++;
        }
    }
    if(L!=R){
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        ans *= i;
        ans %= MOD;
    }

    cout << ans << endl;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
