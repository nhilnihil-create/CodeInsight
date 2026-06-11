#include<bits/stdc++.h>
#define EM 1000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
LL mod = 1e9+7;
using vint = vector<int>;
using vLL = vector<LL>;
using vvint = vector<vector<int>>;
using vvLL = vector<vector<LL>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


vector<vector<int>> G(300010);
vector<int> d(300010, -1);
vector<int> used(300010, 0);

int main(){
    int N, M, S, T;
    cin >> N >> M;
    for(int i = 0;i < M;i++){
        int u, v;
        cin >> u >> v;
        u--;    v--;
        G[3*u].push_back(3*v+1);
        G[3*u+1].push_back(3*v+2);
        G[3*u+2].push_back((3*v));
    }
    cin >> S >> T;
    S--;    T--;
    queue<int>  que;
    que.push(3*S);
    d[3*S] = 0;
    used[3*S] = 1;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(auto s : G[u]){
            if(!used[s]){
                d[s] = d[u]+1;
                used[s] = 1;
                que.push(s);
            }
        }
    }
    if(d[3*T] == -1)   cout << -1 << endl;
    else    cout << (d[3*T]/3) << endl;
}