#include <bits/stdc++.h>
using namespace std;

// 参考資料 : https://drken1215.hatenablog.com/entry/2020/04/25/032000  O( n*log(a) )
// xor は各桁で考えるのが定石 （二進数で考える）
// k 桁目の合計値が 1 増えるのは、k 桁目に(0, 1)の組み合わせのペアがあるとき
// 上記組み合わせは k 桁目が0の数をp個, k 桁目が1の数をq個, とすると pq 通りある
// 二進数のため、k 桁目の合計値が 1 増えるのは、2^k の増加に等しい

#define N_DIGIT_TWO 60
#define MOD 1000000007

int main(void){
    int n;
    long cntOne[N_DIGIT_TWO];
    cin >> n;
    for (int i = 0; i < N_DIGIT_TWO; i++){
        cntOne[i] = 0;
    }
    
    for (int i = 0; i < n; i++){
        long a;
        cin >> a;
        for (int j = 0; j < N_DIGIT_TWO; j++){
            cntOne[j] += (a>>j)&1;
        }
    }
    
    long ans = 0;
    long digit;
    for (int i = 0; i < N_DIGIT_TWO; i++){
        long pattern = cntOne[i] * ( n - cntOne[i] ) % MOD;
        if (i == 0){ digit = 1; }
        else { digit = digit * 2 % MOD; }
        ans = ( ans + ( digit * pattern % MOD ) ) % MOD;
    }

    cout << ans << endl;

    return 0;
}
