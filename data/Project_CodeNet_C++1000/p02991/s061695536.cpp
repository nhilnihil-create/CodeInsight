#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;



int main(){
    int N, M; cin >> N >> M;
    vector<vector<int>> to(N);
    rep(i,M){
        int u, v; cin >> u >> v;
        u--;
        v--;
        to[u].push_back(v);
    }
    int S, T; cin >> S >> T;
    S--;
    T--;

    vector<vector<int>> dist(N, vector<int>(3,-1));
    dist[S][0] = 0;
    
    queue<pair<int, int>> que;
    que.push(make_pair(S,0));
    
    while(!que.empty()){
        int vertex = que.front().first;
        int count = que.front().second;
        int nc = (count+1)%3;
        que.pop();
        for (auto nv : to[vertex]){
            if (dist[nv][nc] != -1) continue;
            dist[nv][nc] = dist[vertex][count]+1;
            que.push(make_pair(nv, nc));
        }
    }

    int ans = dist[T][0];
    if (ans != -1) ans /= 3;
    cout << ans << endl;
}

