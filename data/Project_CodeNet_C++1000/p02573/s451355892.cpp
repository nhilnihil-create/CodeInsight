#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int n,m;
vector <int> par;     //親
vector <int> ran;    //木の深さ

//n要素で初期化
void inti(int n){
    for(int i=0; i<n; i++){
        par.push_back(i);
        ran.push_back(0);
    }
}

//木の根を求める
int find(int x){
    if(par[x] == x){
        return x;
    }
    else{
        return par[x] = find(par[x]);
    }
}

//xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(ran[x] < ran[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(ran[x] == ran[y]) ran[x]++;
    }
}

//xとyが同じ集合に属するか否か
bool same(int x,int y){
    return find(x) == find(y);
}

void solve(){
    cin >> n >> m;
    inti(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        unite(a,b);
    }
    
    vector <int> group(n);
    rep(i,n){
        int gr = find(i);
        group[gr]++;
    }

    sort(all(group));
    cout << group[n-1] << endl;
}

int main(){
    solve();
}