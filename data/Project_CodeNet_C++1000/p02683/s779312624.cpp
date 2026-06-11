#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

bool check(vector<int> und, int x){
    rep(i, und.size()){
        if(und[i]<x)return false;
    }
    return true;
}

int main(){
    int m, n, x;
    cin >> n >> m >> x;
    
    vector<vector<int>> a;
    vector<int> c;
    a.resize(n);
    c.resize(n);
    rep(i, n){
        cin >> c[i];
        a[i].resize(m);
        rep(j, m)cin >> a[i][j];
    }
    
    
    int ans = 1<<30;
    rep(i, (1<<n)){
        vector<int> und(m, 0);
        int cost=0;
        rep(j, n){
            if(i&(1<<j)){
                cost+=c[j];
                rep(k, m)und[k]+=a[j][k];
            }
        }
        if(check(und, x))ans = cost<ans? cost: ans;
    }
    
    if(ans == 1<<30)ans=-1;
    cout << ans << endl;
}