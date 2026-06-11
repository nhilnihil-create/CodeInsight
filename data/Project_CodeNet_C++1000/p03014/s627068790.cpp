#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int H, W;
vector<string> S;

vector<vector<int>> L,R,U,D;

int search(int h, int w){

    // 左
    // 一つ左の要素が探索済みの場合
    if (w-1 >= 0 && L[h][w-1] > 0){
        L[h][w] = L[h][w-1] + 1;
    }
    else{
        int count = 0;
        for(int i = 1; i < W; i++){
            if (w-i >= 0 && S[h][w-i] == '.') count++;
            else break;
        }
        L[h][w] = count;
    }

    // 右
    // 一つ左の要素が探索済みの場合
    if (w-1 >= 0 && R[h][w-1] != -1){
        R[h][w] = R[h][w-1] - 1;
    }
    else{
        int count = 0;
        for(int i = 1; i < W; i++){
            if (w+i < W && S[h][w+i] == '.') count++;
            else break;
        }
        R[h][w] = count;
    }

    // 上
    // 一つ上の要素が探索済みの場合
    if (h-1 >= 0 && U[h-1][w] > 0){
        U[h][w] = U[h-1][w] + 1;
    }
    else{
        int count = 0;
        for (int i = 1; i < H; i++){
            if (h-i >= 0 && S[h-i][w] == '.') count++;
            else break;
        }
        U[h][w] = count;
    }

    // 下
    // 一つ上の要素が探索済みの場合
    if (h-1 >= 0 && D[h-1][w] != -1){
        D[h][w] = D[h-1][w] - 1;
    }
    else{
        int count = 0;
        for (int i = 1; i < H; i++){
            if (h+i < H && S[h+i][w] == '.') count++;
            else break;
        }
        D[h][w] = count;
    }

    //cout << h << " " << w << endl;
    //cout << L[h][w] << " " << R[h][w] << " " << U[h][w] << " " << D[h][w] << endl;

    return L[h][w] + R[h][w] + U[h][w] + D[h][w] + 1;
}


int main(){
    cin >> H >> W;
    S.assign(H,"");
    rep(i,H) cin >> S[i];

    L.assign(H, vector<int>(W, -1));
    R.assign(H, vector<int>(W, -1));
    U.assign(H, vector<int>(W, -1));
    D.assign(H, vector<int>(W, -1));
    int ans = 0;
    rep(i,H){
        rep(j,W){
            if (S[i][j] == '.') {
                ans = max(ans, search(i,j));
            }
        }
    }

    cout << ans << endl;
    
}