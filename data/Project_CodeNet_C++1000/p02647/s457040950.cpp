#include <bits/stdc++.h> //全てのヘッダファイルをインクルード

//ループ
#define REP(i, n) for(int i = 0; i < n; i++) //普通のループ
#define REPR(i, n) for(int i = n; i >= 0; i--) //逆ループ
#define FOR(i, m, n) for(int i = m; i < n; i++) //最初の数値を指定したループ

//型名省略
typedef long long ll;
//配列要素数
static const int MAX = 200000;
//値
static const ll MX = 1e18;

using namespace std;

//#include "./lib/generic/search.h"

#define M 1064527

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    REP(i,N) cin >> a[i];
    REP(j,K){
        vector<int> b(N+1);
        REP(i,N){
            int l = max(0, i-a[i]);
            int r = min(N, i+a[i]+1);
            b[l]++; b[r]--;
        }
        REP(i,N) b[i+1]+=b[i];
        b.pop_back();
        if(a==b) break;
        a=b;
    }
    REP(i, N) cout << a[i] << endl;
    return 0;
}