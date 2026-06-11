#include <iostream>
#include <bitset>
#include <climits>
#include <algorithm>
using namespace std;

#define N_MAX 12
#define M_MAX 12

int N, M, X;
int C[N_MAX];
int A[N_MAX][M_MAX];

void input(){

    cin >> N >> M >> X;
    for (int i=0;i<N;i++){
        cin >> C[i];
        for (int j=0;j<M;j++){
            cin >> A[i][j];
        }
    }
}

void solve(){
    // i番目の本(値段C[i])を読むと、j番目のアルゴリズムの理解度がA[i][j]だけ上がる。
    // 全てのアルゴリズムの理解度をX以上にすることは可能か？-->全部買った時が最大
    // ビット全探索ができるよ。
    // 選択したiについて、sigma_i(C[i])をとる。sigma_i(A[i][j])の最小値をとる。最小値がX以上ならオッケー
    // sigma_i(C[i])の最小値を出力する。
    int ans = INT_MAX;

    for (int k = 0; k < (1 << N); k++){ //本の選び方パターン
        int sum_C = 0;
        int sum_A[M_MAX] = {}; //これで0初期化
        bitset<N_MAX> bit_counter(k);

        for (int i = 0; i < N; i++){ //本の番号i
            if (bit_counter[i]){
                sum_C += C[i];
                for (int j=0;j<M;j++){ //アルゴリズム番号j
                    sum_A[j] += A[i][j];
                }
            }
        }
        // sum_Aの最小値がX以上ならば
        if (*min_element(sum_A, sum_A+M) >= X){
            //sum_Cが前の値と比べて小さければansに代入
            ans = min(ans,sum_C);
        }
    }
    if (ans == INT_MAX){
        ans = -1;
    }
    cout << ans << endl;
}

int main(){
    input();
    solve();
    return 0;
}
