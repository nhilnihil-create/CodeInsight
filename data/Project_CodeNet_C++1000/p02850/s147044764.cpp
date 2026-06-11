#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> P;
vector<vector<int>> G;
map<P, int> m;
vector<int> color;
void dfs(int s, int n){
    int co = 1;
    int pre;
    for(int j:G[s]){
        if(j < s) continue;
        if(co == n){
            color[m[P(s, j)]] = co + 1;
            pre = co + 1;
            co += 2;
        }
        else{
            color[m[P(s, j)]] = co;
            pre = co;
            co++;
        }
        dfs(j, pre);
    }
}
int main(){
    long long N;
    cin >> N;
    G.resize(N);
    color.resize(N - 1);
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        m[P(a, b)] = i;
    }
    dfs(0, -1);
    int ans = 0;
    for(int i =0 ; i < N - 1; i++) ans = max(ans, color[i]);
    cout << ans << endl;
    for(int i = 0; i < N - 1; i++)cout<< color[i] << endl;
}