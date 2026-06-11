#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;



int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> M(h, vector<char>(w));
    rep(i, h){
        rep(j, w){
            cin >> M[i][j];
        }
    }

    vector<vector<int>> cnt1(h, vector<int>(w, 0)), cnt2(h, vector<int>(w, 0));

    rep(i, h){
        rep(j, w){
        int cnt = 0;
            if(M[i][j] == '.'){
                for (int k = j; k < w; ++k) {
                    if(M[i][k] == '.'){
                        cnt++;
                    }else{
                        //cnt = 0;
                        break;
                    }
                }
                for (int k = j; k < w; ++k) {
                    if(M[i][k] == '.'){
                        cnt1[i][k] = cnt;
                    }else{
                        break;
                    }
                }
                j += cnt;
            }
        }
    }

    rep(i, w){
        rep(j, h){
        int cnt = 0;
            if(M[j][i] == '.'){
                for (int k = j; k < h; ++k) {
                    if(M[k][i] == '.'){
                        cnt++;
                    }else{
                        break;
                    }
                }
                for (int k = j; k < h; ++k) {
                    if(M[k][i] == '.'){
                        cnt2[k][i] = cnt;
                    }else{
                        break;
                    }
                }
                j += cnt;
            }
        }
    }


    int ans = 0;
    rep(i, h){
        rep(j, w){
            if(M[i][j] == '.'){
                ans = max(ans, cnt1[i][j] + cnt2[i][j] - 1);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
