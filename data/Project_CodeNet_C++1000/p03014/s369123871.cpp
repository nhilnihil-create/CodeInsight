#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> f(h);
    rep(i,h) cin >> f[i];

    vector<vector<int>> x(h, vector<int>(w)), y(h, vector<int>(w));
    rep(i,h){
        int cnt = 0;
        vector<int> itr;
        rep(j,w){
            if(f[i][j] == '.'){
                cnt++;
                itr.push_back(j);
            }
            else{
                for(auto p : itr) x[i][p] = cnt;
                cnt = 0;
                itr.clear();
            }
        }
        if(!itr.empty()) for(auto p : itr) x[i][p] = cnt;
    }

    rep(j,w){
        int cnt = 0;
        vector<int> itr;
        rep(i,h){
            if(f[i][j] == '.'){
                cnt++;
                itr.push_back(i);
            }
            else{
                for(auto p : itr) y[p][j] = cnt;
                cnt = 0;
                itr.clear();
            }
        }
        if(!itr.empty()) for(auto p : itr) y[p][j] = cnt;
    }
    int ans = 0;
    rep(i,h) rep(j,w) ans = max(ans, x[i][j] + y[i][j] - 1);
    cout << ans << endl;
}