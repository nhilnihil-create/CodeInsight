#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define IO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef long double ld;

using namespace std;
const ll INF = 1e18;
const int mod = 1e9 + 7, N = 1e5 + 5, inf = 1e9;
int n, m, s, t, u, v;
vector<int>arr[N];

int bfs()
{
    queue<pair<int, int>>q;
    bool vis[N][5] = {};
    q.push({ s, 0 });
    vis[s][0] = true;
    while(q.size())
    {
        u = q.front().first;
        int ken = q.front().second;
        q.pop();

        if(u == t && ken % 3 == 0)
            return ken / 3;

        for(auto i : arr[u])
        {
            if(!vis[i][(ken + 1) % 3])
            {
                q.push({i, ken + 1});
                vis[i][(ken + 1) % 3] =true;
            }
        }
    }
    return -1;
}

int main()
{
    IO;
    cin >> n >> m;
    for(int i =0; i < m; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
    }
    cin >> s >> t;
    cout << bfs() << '\n';
    return 0;
}