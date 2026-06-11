#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 510000;
const int MOD = 1000000007;

/*long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}*/

int main() {
    int H, W;
    cin >> H >> W;
    char S[H][W];

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) {
            cin >> S[i][j];
        }
    }
    int S_count_1[H][W] = {0};
    int sum = 0;
    for(int i = 0; i < H; i++) {
        sum = 0;
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') { S_count_1[i][j] = 0; sum = 0; }
            else if(S[i][j] == '.') { S_count_1[i][j] = sum; sum++; }
        }
    }
    sum = 0;
    int S_count_2[H][W] = {0};

    for(int i = 0; i < H; i++) {
        sum = 0;
        for(int j = W - 1; j >= 0; j--) {
            if(S[i][j] == '#') { S_count_2[i][j] = 0; sum = 0; }
            else if(S[i][j] == '.') { S_count_2[i][j] = sum; sum++; }
        }
    }

    int S_count_3[H][W] = {0};
    sum = 0;

    for(int j = 0; j < W; j++) {
        sum = 0;
        for(int i = 0; i < H; i++) {
            if(S[i][j] == '#') { S_count_3[i][j] = 0; sum = 0; }
            else if(S[i][j] == '.') { S_count_3[i][j] = sum; sum++; } 
        }
    }
    int S_count_4[H][W] = {0};
    sum = 0;
    for(int j = 0; j < W; j++) {
        sum = 0;
        for(int i = H - 1; i >= 0; i--) {
            if(S[i][j] == '#') { S_count_4[i][j] = 0; sum = 0; }
            else if(S[i][j] == '.') { S_count_4[i][j] = sum; sum++; }        
        }
    }
    int max = -100;
    for(int i = 0; i < W; i++) {
        for(int j = 0; j < H; j++) {
            if(S[j][i] == '.') {
                if(max < 1 + S_count_1[j][i] + S_count_2[j][i] + S_count_3[j][i] + S_count_4[j][i]) max = S_count_1[j][i] + S_count_2[j][i] + S_count_3[j][i] + S_count_4[j][i] + 1;
            }
        }
    }

    cout << max << endl;
    return 0;
}