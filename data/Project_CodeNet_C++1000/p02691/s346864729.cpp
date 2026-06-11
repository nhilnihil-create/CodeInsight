#include <bits/stdc++.h>
using namespace std;

// 解説資料：https://img.atcoder.jp/abc166/editorial.pdf
// 変数分離により、計算量を減らしている
// 連想配列の意識も足りなかった（思いつく可能性はあったと思う）

#define NPERSON 200000

int main() {
    // 入力
    int nPerson;
    cin >> nPerson;
    int a[NPERSON+1];
    for (int i = 1; i <= nPerson; i++){   
        cin >> a[i];
    }
    
    // i + A[i] を求め、連想配列で格納する（i + A[i] を満たす i の数を配列に記録する）
    int cntList[NPERSON + 1];      // 
    for (int i = 1; i <= nPerson; i++){
        cntList[i] = 0;
    }
    
    for (int i = 1; i <= nPerson; i++){
        int tmp = i + a[i];
        if(tmp > nPerson){
            continue;
        }
        cntList[tmp]++;
    }

    // j - A[j] を求め、その値の連想配列へアクセスすることで、条件を満たす (i + A[i] = j - A[j] となる) ペア数がわかるので、その値を加算する
    long cnt = 0;
    for (int i = 1; i <= nPerson; i++){
        int tmp = i - a[i];
        if(tmp <= 0){
            continue;
        }
        cnt += (long)cntList[tmp];
    }

    // 出力
    cout << cnt << endl;

    return 0;
}
