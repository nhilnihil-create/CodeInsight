#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const int inf = (int)1e10;
const int mod = (int)1e9 + 7;
typedef pair<int, int> P;

int n;
P ab[(int)1e5];
vector<vector<int>> G((int)1e5);
map<P, int> color;

queue<P> que;
int bfs(int v, int number){
    que.push(P(v, -1));
    color[P(-1, v)] = 0;
    while(que.size()){
        P p = que.front(); que.pop();
        
        int num = 1;
        for(auto new_v:G[p.first]){
            if(new_v == p.second) continue;
            if(color.count(P(p.first, new_v))) continue;
            if(num == color[P(p.second, p.first)]) num++;
            color[P(p.first, new_v)] = num;
            que.push(P(new_v, p.first));
            if(number < num) number = num;
            num ++;
        }
    }
    return number;
}

int main(){
    cin >> n;
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        ab[i] = P(a - 1, b - 1);
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    int res = bfs(0, 0);
    cout << res << endl;
    rep(i, n - 1) cout << color[ab[i]] << endl;
}