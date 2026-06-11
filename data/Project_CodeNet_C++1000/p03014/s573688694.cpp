#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int h,w;
    cin >> h >> w;
    vector<vector<char>> map(h+1, vector<char>(w+1));
    vector<vector<int>> yoko(h, vector<int>(w));
    vector<vector<int>> tate(h, vector<int>(w));
    rep(i,h)rep(j,w) cin >> map[i][j];

        
    rep(i,h){
        int cnt = 0;
        int begin = 0;
        rep(j,w+1){
            if(map[i][j]=='#'||j==w){
                for(int k=begin; k<=begin+cnt-1; k++) yoko[i][k] = cnt;
                cnt = 0;
                begin = j+1;
            }else{
                cnt++;
            }
        }
    }

    rep(j,w){
        int cnt = 0;
        int begin = 0;
        rep(i,h+1){
            if(map[i][j]=='#'||i==h){
                for(int k=begin; k<=begin+cnt-1; k++) tate[k][j] = cnt;
                cnt = 0;
                begin = i+1;
            }else{
                cnt++;
            }
        }
    }

    int ans = 0;
    rep(i,h)rep(j,w) ans = max(ans, yoko[i][j] + tate[i][j] - 1);

    cout << ans << endl;
    return 0;
}