#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

vector<int> grid[200000];
ll score[200000];
bool seen[200000];

void dps(int now)
{
    for (auto next : grid[now])
    {
        if (seen[next])
        {
            continue;
        }
        score[next] += score[now];
        seen[next] = true;
        dps(next);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p >> x;
        --p;
        score[p] += x;
    }
    seen[0] = true;
    dps(0);
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            cout << ' ';
        }
        cout << score[i];
    }
    cout << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}