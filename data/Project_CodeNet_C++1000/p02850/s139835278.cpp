#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> list(n - 1);
    vector<int> G[n];
    vector<map<int, int>> ans(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        list[i].first = a;
        list[i].second = b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, int(G[i].size()));
    }
    vector<bool> seen(n);
    seen[0] = true;
    queue<pair<int, int>> qe; // 頂点，親とどの色でつながっているか
    qe.push(make_pair(0, 0));
    while (!qe.empty())
    {
        auto nows = qe.front();
        qe.pop();
        int now = nows.first;
        int use = nows.second;
        int color = 1;
        for (auto next : G[now])
        {
            if (seen[next])
            {
                continue;
            }
            if (color == use)
            {
                ++color;
            }
            ans[now][next] = color;
            // cout << now << ':' << next << ':' << color << endl;
            qe.push(make_pair(next, color));
            seen[next] = true;
            ++color;
        }
    }
    cout << maxi << endl;
    for (auto l : list)
    {
        cout << ans[l.first][l.second] << endl;
    }
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
};