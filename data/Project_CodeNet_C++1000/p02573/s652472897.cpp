#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

struct UnionFind{
    vector<int> r;

    UnionFind(int N){
        r = vector<int> (N,-1);
    }

    int root(int x){
        if(r[x]<0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x==y) return false;
        if(r[x]>r[y]) swap(x,y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int size(int x) {
        return -r[root(x)];
    }
};

int main(){
    int n,m; cin >> n >> m;

    UnionFind UF(n);
    for(int i=0; i<m;i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        UF.unite(a,b);
    }

    int ans = 0;
    rep(i,n) ans = max(ans,UF.size(i));

    cout << ans << endl;
}