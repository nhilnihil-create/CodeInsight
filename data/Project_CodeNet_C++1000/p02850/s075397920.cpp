#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<Int,Int> P;


Int N;
vector<vector<Int>> G(100010);
map<P,Int> edge_to_num;
vector<Int> color(100010);
Int K = 0;

void dfs(int i, int k = -1, int cng = -1) {
    Int c = 1;
    rep(j, G[i].size()) {
        if (G[i][j] != k) {
            if (c == cng) c++;
            color[edge_to_num[make_pair(i,G[i][j])]] = c;
            dfs(G[i][j], i, c);
            K = max(K, c);
            c++;
        }
    }
    return;
}


int main(){ 
    cin >> N;
    

    vector<Int> a(N-1), b(N-1);
    
    rep(i,N-1) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
        edge_to_num[make_pair(a[i],b[i])] = i;
        edge_to_num[make_pair(b[i],a[i])] = i;
    }


    dfs(0);

    cout << K << endl;

    rep(i,N-1) cout << color[i] << endl;
}


