#include <bits/stdc++.h>
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
typedef long long ll;
using namespace std;

int h, w, k;
vector<vector<int>> c;
int del;  //何個黒を赤に変えればいいか

int main(){
    int cnt = 0;
    cin >> h >> w >> k;
    c.resize(h);
    rep(i, h){
        c[i].resize(w);
        rep(j, w){
            char a;
            cin >> a;
            c[i][j] = (a=='#')? 1: 0;
            if(c[i][j]==1)cnt++;
        }
    }
    
    del = cnt - k;
    
    int ans = 0;
    
    rep(i, (1<<h)){
        rep(j, (1<<w)){
            int cnt=0;
            rep(k, h){
                rep(l, w){
                    if(c[k][l]==1 && !((1<<k)&i) && !((1<<l)&j))cnt++;
                }
            }
            if(cnt==k)ans++;
        }
    }
    
    cout << ans << endl; 
}