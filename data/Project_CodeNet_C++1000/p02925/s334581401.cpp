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

int main()
{
    long long N;
    scanf("%lld", &N);
    vector<queue<int>> match(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            match[i].push(tmp);
        }
    }
    bool cannot = true;
    bool allFinished = true;
    vector<bool> already(N, false);
    int ans = 0;
    int cnt = 0;
    while (cnt < 10000)
    {
        cnt++;
        cannot = true;
        allFinished = true;

        for (int i = 0; i < N; i++)
        {
            if (match[i].size() > 0)
            {
                allFinished = false;
            }
            else
            {
                continue;
            }
            if (!already[i])
            {
                int candidate = match[i].front() - 1;
                if (match[candidate].size() != 0)
                {
                    if (match[candidate].front() == i + 1)
                    {
                        if (!already[candidate])
                        {
                            cannot = false;
                            match[i].pop();
                            match[candidate].pop();
                            already[i] = true;
                            already[candidate] = true;
                        }
                    }
                }
            }
        }
        if (allFinished)
        {
            cout << ans << endl;
            return 0;
        }
        if (cannot)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            ans++;
            already.assign(N, false);
        }
    }
    cout << N*(N-1)/2 << endl;
    return 0;
}
