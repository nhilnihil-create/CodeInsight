#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> to;
vector<int> dist, used;
typedef pair<int, int> P;
int N;
vector<int> flag;
int dfs(int s){
    if(used[s] == 1) {
        if(flag[s] == 0) return -1; 
        return dist[s];
    }
    used[s] = 1;
    dist[s] = 0;
    for(int i: to[s]){
        int res = dfs(i);
        if(res == -1) return -1;
        dist[s] = max(dist[s], res + 1);
    }
    flag[s] = 1;
    return dist[s];
} 
int main(){
    cin >> N;
    vector<vector<int>> a(N, vector<int> (N - 1));
    to.resize(N * (N - 1) / 2);
    for(int i =0 ; i< N; i++){
        for(int j = 0;j < N - 1; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ind[N][N];
    int cnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            ind[i][j] = cnt;
            cnt++;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 2; j++){
            int s1 = i, t1 = a[i][j], t2 = a[i][j + 1];
            int s2 = s1;
            if(s1 > t1) swap(s1, t1);
            if(s2 > t2) swap(s2, t2);
            int ind1 = ind[s1][t1], ind2 = ind[s2][t2];
            to[ind2].push_back(ind1);
        }
    }
    dist.resize(N * (N - 1) / 2, 0);
    used.resize(N * (N - 1) / 2, 0);
    flag.resize(N * (N - 1) / 2, 0);
    int ans = 0;
    for(int i = 0; i < N * (N - 1) / 2; i++){
        int res = dfs(i);
        if(res == -1){
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, dfs(i));
    }
    cout << ans + 1 << endl;
}