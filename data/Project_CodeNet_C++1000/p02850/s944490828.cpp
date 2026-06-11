#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;

vector<vector<int>> v;
map<P,int> c;
int vm = 0;

void bfs(int i, int b) {
    int n = 1;
    rep(j,v[i].size()) {
        int mae, usi;
        mae = min(i,v[i][j]);
        usi = max(i,v[i][j]);
        
        if(c[P(mae,usi)] != 0)
            continue;
        if(n == b)
            n++;
        c[P(mae,usi)] = n;
        
        bfs(v[i][j],n);
        
        n++;
    }
}

int main() {
    int n;
    cin >> n;
    
    v.resize(n);
    vector<P> e(n-1);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        
        e[i].first = a;
        e[i].second = b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int root = -1;
    rep(i,n) {
        if(vm < v[i].size()) {
            vm = (int)v[i].size();
            root = i;
        }
    }
    //cout << root << endl;
    
    bfs(root,0);
    
    cout << vm << endl;
    rep(i,n-1) {
        cout << c[e[i]] << endl;
    }
    
    
    return 0;
}
