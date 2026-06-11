#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int N_MAX = 200005;
int counter[N_MAX];
int plusc[N_MAX];
vector<int> root[N_MAX];

void dfs(int n, int p, int num){
    int nownum = num + plusc[n];
    counter[n] = nownum;
    for(auto u: root[n]){
        if (u == p)continue;
        dfs(u, n, nownum);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        root[a].push_back(b);
        root[b].push_back(a);
    }
    memset(plusc, 0, sizeof(plusc));
    for(int i = 0; i < q; i++){
        int p, x;
        cin >> p >> x;
        plusc[p] += x;
    }

    dfs(1, -1, 0);
    for(int i = 1; i <= n; i++){
        cout << counter[i];
        if (i != n)cout << " ";
    }
    return 0;
}