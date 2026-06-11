#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, init, n) for (int i = init; i < (n); i++)

using namespace std;
using ll = long long int;
using P = pair<int, int>;
using T = tuple<int, int, int>;
using edge = struct
{
    int to, cost;
};

const int MOD = 1e9 + 7;
const int iINF = 1e9;
const long long int llINF = 1e18;
const double PI = acos(-1.0);

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<int> graph[10000];

int h[100000];

int main()
{
    int V, E;
    cin >> V >> E;
    rep(i, E)
    {
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        h[t]++;
    }

    stack<int> st;

    rep(i, V) if (h[i] == 0) st.push(i);

    vector<int> ans;

    while (st.size())
    {
        int i = st.top();
        st.pop();
        ans.push_back(i);

        for (auto e : graph[i])
        {
            h[e]--;

            if (h[e] == 0)
                st.push(e);
        }
    }

    for (int i : ans)
        cout << i << endl;

    return 0;
}
