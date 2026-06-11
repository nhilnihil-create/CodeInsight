#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> field(h);
    rep(i, h) cin >> field[i];
    vector<vector<int>> yoko(h, vector<int>(w, 0));
    vector<vector<int>> tate(h, vector<int>(w, 0));
    rep(i, h){
        vector<bool> done(w, 0);
        rep(j, w){
            if(field[i][j] == '#') continue;
            if(done[j]) continue;
            int l = 0;
            while(j + l < w){
                if(field[i][j + l] == '.') l++;
                else break;
            }
            rep(k, l){
                yoko[i][j + k] = l;
                done[j + k] = true;
            }
        }
    }
    rep(i, w){
        vector<bool> done(h, 0);
        rep(j, h){
            if(field[j][i] == '#') continue;
            if(done[j]) continue;
            int l = 0;
            while(j + l < h){
                if(field[j + l][i] == '.') l++;
                else break;
            }
            rep(k, l){
                tate[j + k][i] = l;
                done[j + k] = true;
            }
        }
    }
    int ans = 0;
    rep(i, h){
        rep(j, w){
            ans = max(ans, tate[i][j] + yoko[i][j] - 1);
        }
    }
    cout << ans << endl;
    return 0;
}