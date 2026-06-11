#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void dfs(int now,vector<int> &parent, 
        map<pair<int,int>,int> &edge_color, vector<vector<int>> &G){
    int col=0;
    int now_p = parent.at(now);
    rep(i, (int)G.at(now).size()){
        pair<int,int> p=make_pair(min(now,now_p), max(now,now_p));
        int c;
        if(now==0)  c=-1;
        else  c=edge_color[p];
        int go=G.at(now).at(i);
        if(go != parent.at(now)){
            if(col==c) col++;
            parent.at(go) = now;
            pair<int, int> q=make_pair(min(now,go), max(now,go));
            edge_color[q] = col;
            col++;
            dfs(go, parent, edge_color,G);
        }
    }
}


int main(){
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<pair<int,int>> edge_num(n-1);
    map<pair<int,int>,int> edge_color;
    rep(i, n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        pair<int, int> p;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
        p=make_pair(a,b);
        edge_num.at(i) = p;
    }
    vector<int> parent(n,0);
    dfs(0, parent, edge_color, G);
    int ans=0;
    rep(i,n){
        ans = max(ans, (int)G.at(i).size());
    }
    cout << ans << endl;
    rep(i, n-1){
        pair<int, int> p;
        p=edge_num.at(i);
        cout << edge_color.at(p) + 1 << endl;
    }
}
