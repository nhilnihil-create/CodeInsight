#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1 LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    int H,W;cin >> H >> W;
    int A,B;cin >> A >> B;
    vector<vector<int>> s(H,vector<int>(W));
    rep(i,H)rep(j,W){
        if(i < B){
            if(j < A)s[i][j] = 0;
            else s[i][j] = 1;
        }
        else{
            if(j < A)s[i][j] = 1;
            else s[i][j] = 0;
        }
    }

    rep(i,H){
        rep(j,W)cout << s[i][j];
        cout  << endl;
    }

}