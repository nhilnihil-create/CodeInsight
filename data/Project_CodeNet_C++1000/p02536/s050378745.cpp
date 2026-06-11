#include <bits/stdc++.h>
using namespace std;
#define ll long long int;
#define P pair<int, int>;
#define rep(i, n) for(int i = 0; i < (n); i++)

int p[100010];

int root(int x){
    if(p[x] == x) return x;
    return p[x] = root(p[x]);
}

void unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    p[x] = y;
}

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, n){
        p[i] = i;
    }
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        unite(a, b);
    }
    set<int> out;
    rep(i, n){
        out.insert(root(i));
    }
    cout << out.size() - 1 << endl;
}