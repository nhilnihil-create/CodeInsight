#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int> > path;
queue<tuple<int, int, int> > q;
vector<vector<bool> > seen;

typedef long long ll;

ll countv = 0;
ll K = 0;


#define MOD (1000000007)

void push(int num, int timing, int count) {
    if(seen[num][timing] != true) {
        q.push(make_tuple(num, timing, count));
        seen[num][timing] = true;

        //cout << num+1 << ":" << timing << "-" << count << endl;
    }
}


int main() {
    ll N, M;
    cin >> N >> M;


    path.assign(N, vector<int>());
    seen.assign(N, vector<bool>(3, false));
    for(ll i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--;v--;
        path[u].push_back(v);
        //path[v].push_back(u);
    }

    ll S, T;
    cin >> S >> T ;
    S--; T--;

    push(S, 0, 0);
    while(q.size() >= 1) {
        tuple<int, int, int> p = q.front(); q.pop();
        int current = get<0>(p);
        int timing = get<1>(p);
        int count = get<2>(p);
        if(current == T && timing == 0) {
            cout << count / 3 << endl;
            return 0;
        }
        for(ll i = 0; i < path[current].size(); i++) push(path[current][i], (timing + 1 ) % 3, count+1);
    }

    cout << -1 << endl;
}
