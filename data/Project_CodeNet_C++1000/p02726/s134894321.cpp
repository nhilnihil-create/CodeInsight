#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;
const double PI = acos(-1);

vector<int> to[2000];

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    rep(i, n - 1) {
        to[i].push_back(i + 1);
        to[i + 1].push_back(i);
    }
    to[x - 1].push_back(y - 1);
    to[y - 1].push_back(x - 1);

    vector<int> ans(n);
    rep(i, n) {
        queue<int> que;
        que.push(i);
        vector<int> dist(n, -1);
        dist[i] = 0;
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            for (auto j : to[now]) {
                if (dist[j] != -1) continue;
                que.push(j);
                dist[j] = dist[now] + 1;
                if (j > i) ans[dist[j]]++;
            }
        }
    }

    rep(i, n - 1) {
        cout << ans[i + 1] << endl;
    }
    return 0;
}