#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
int A[1010][1010];
vector<int> G[1000010];
bool used[1000010];
bool ap[1000010];
bool flag;
int ans = -1;
int in[1000010];
int path[1000010];

int exchange(int a, int b){
    int mx = max(a, b);
    int mn = min(a, b);
    return mx * N + mn;
}

void dfs(int v){

    if(used[v]){
        flag = true;
        return;
    }
    if(path[v] != 0) return;
    
    used[v] = true;
    path[v] = 1;
    for(auto u : G[v]){
        dfs(u);
        chmax(path[v], path[u] + 1);
    }
    used[v] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i){
        for(int j = 1; j < N; ++j){
            cin >> A[i][j];
            A[i][j]--;
            ap[exchange(i, A[i][j])] = true;
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 1; j + 1 < N; ++j){
            G[exchange(i, A[i][j])].push_back(exchange(i, A[i][j + 1]));
            in[exchange(i, A[i][j + 1])]++;
        }
    }
    for(int i = 0; i < N * N; i++){
        if(in[i] == 0 && ap[i]) dfs(i), chmax(ans, path[i]);
    }
    cout << (flag ? -1 : ans) << endl;
    return 0;
}
