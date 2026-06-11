#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
const int INF = 1001001001;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> g[N];
    for(int i=0;i <M; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    int S, T;
    cin >> S >> T;
    S--; T--;

    int d[N][3];
    for(int i=0; i<N; i++){
        d[i][0] = INF;
        d[i][1] = INF;
        d[i][2] = INF;
    }
    d[S][0] = 0;

    priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> q;
    q.push(make_pair(0, P(S, 0)));
    while(!q.empty()){
        int now = q.top().second.first;
        int mod = q.top().second.second;
        int l = q.top().first;
        q.pop();
        if(l != d[now][mod]) continue;
        for(auto next : g[now]){
            if(d[next][(mod+1)%3] > d[now][mod] + 1){
                d[next][(mod+1)%3] = d[now][mod] + 1;
                q.push(make_pair(d[next][(mod+1)%3], P(next, (mod+1)%3)));
            }
        }
    }

    int ans;
    if(d[T][0] == INF) ans = -1;
    else ans = d[T][0]/3;
    cout << ans << endl;

    return 0;
}
