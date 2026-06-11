#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    vector<vector<vector<int>>> cnt(H, vector<vector<int>>(W, vector<int>(4)));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(j == 0){
                if(S[i][j] == '.') cnt[i][j][0] = 1;
            }
            else{
                if(S[i][j] == '.') cnt[i][j][0] = cnt[i][j - 1][0] + 1;
            }
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = W - 1; j >= 0; j--){
            if(j == W - 1){
                if(S[i][j] == '.') cnt[i][j][1] = 1;
            }
            else{
                if(S[i][j] == '.') cnt[i][j][1] = cnt[i][j + 1][1] + 1;
            }
        }
    }
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++){
            if(j == 0){
                if(S[j][i] == '.') cnt[j][i][2] = 1;
            }
            else{
                if(S[j][i] == '.') cnt[j][i][2] = cnt[j - 1][i][2] + 1;
            }
        }
    }
    for(int i = 0; i < W; i++){
        for(int j = H - 1; j >= 0; j--){
            if(j == H - 1){
                if(S[j][i] == '.') cnt[j][i][3] = 1;
            }
            else{
                if(S[j][i] == '.') cnt[j][i][3] = cnt[j + 1][i][3] + 1;
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            ll ans = 0;
            for(int k = 0; k < 4; k++){
                ans += cnt[i][j][k];
            }
            res = max(res, ans);
        }
    }
    cout << res - 3 << endl;
}