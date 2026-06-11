#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> G[N];
    map<pair<ll, ll>, ll> eColor;
    vector<pair<ll, ll>> edge;
    REP(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        edge.push_back(make_pair(a, b));
    }

    ll maxV = 0;
    REP(i, N) maxV = max(maxV, (ll)G[i].size());
    vector<ll> vColor(N, -1);
    queue<ll> q;
    vector<bool> visited(N, false);
    q.push(0);
    while(!q.empty())
    {
        ll v = q.front();
        q.pop();
        visited[v] = true;
        ll paintColor;
        if (vColor[v] != -1)
        {
            paintColor = (vColor[v] + 1) % maxV;
        }
        else
        {
            paintColor = 0;
        }
        REPV(iter, G[v])
        {
            if (!visited[*iter])
            {
                q.push(*iter);
                pair<ll, ll> e = make_pair(min(v, *iter), max(v, *iter));
                eColor[e] = paintColor;
                vColor[*iter] = paintColor;
                paintColor = (paintColor + 1) % maxV;
            }
        }
    }

    cout << maxV << endl;
    REP(i, N - 1) cout << eColor[edge[i]] + 1 << endl;
}
