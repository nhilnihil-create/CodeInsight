#include<iostream>
#include<vector>

using namespace std;

#define pii pair<int, int>
#define ft first
#define sd  second

const int N = 1e5+5;

vector<pii> vec[N];
int col[N], ans = 0;

void dfs(int u, int p, int val){
    int k = 1;
    ans = max(ans, val);
    for(auto x: vec[u]){
        if(x.ft != p){
            if(val == k) k++;
            col[x.sd] = k;
            dfs(x.ft, u, k);
            k++;
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        vec[u].push_back({v, i});
        vec[v].push_back({u, i});
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    for(int i = 1;  i< n; i++)
        cout << col[i] << " ";
}
