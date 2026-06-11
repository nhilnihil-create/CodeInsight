#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
using P = pair<int, int>;

const int N_MAX = 100005;
vector<P> edge[N_MAX];
int color[N_MAX];

void dfs(int v, int p=-1, int c=0){
    int col = 1;
    for(P u : edge[v]){
        if (col == c)col++;
        if (u.first == p)continue;
        color[u.second] = col;
        dfs(u.first, v, col);
        col++;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        edge[a].emplace_back(b, i);
        edge[b].emplace_back(a, i);
    }

    memset(color, 0, sizeof(color));
    dfs(1);
    int k = 0;
    for(int i = 0; i < n-1; i++){
        k = max(k, color[i]);
    }
    cout << k << endl;
    for(int i = 0; i < n-1; i++){
        cout << color[i] << endl;
    }
    return 0;
}