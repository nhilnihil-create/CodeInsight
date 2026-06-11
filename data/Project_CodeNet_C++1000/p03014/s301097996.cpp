#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main(){
    int H,W; cin >> H >> W;
    int count = 0, pos = 0, ans = -1;
    vector<string> s(H);
    vector<vector<int>> h(H,vector<int>(W,0)),w(H,vector<int>(W,0));
    rep(i,H) cin >> s[i];

    rep(i,H){
        count = 0;
        rep(j,W){
            if(s[i][j] == '.') {
                count ++;
                w[i][j] = count;
            }else count = 0;
        }
        for(int j = W-2; j >= 0; j --){
            if(w[i][j] != 0) w[i][j] = max(w[i][j],w[i][j+1]);
        }
    }

    rep(i,W){
        count = 0;
        rep(j,H){
            if(s[j][i] == '.') {
                count ++;
                h[j][i] = count;
            }else count = 0;
        }
        for(int j = H-2; j >= 0; j --){
            if(h[j][i] != 0) h[j][i] = max(h[j][i],h[j+1][i]);
        }
    }


    rep(i,H){
        rep(j,W){
            if(s[i][j] == '.') ans = max(ans,h[i][j] + w[i][j]);
        }
    }
    cout << ans-1;



}