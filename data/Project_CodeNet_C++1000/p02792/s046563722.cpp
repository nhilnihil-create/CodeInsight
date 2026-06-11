#include <bits/stdc++.h>
using namespace std;

#define DECIMAL 10

int main(void){
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        // 最大位と最小位の値を算出
        int iTmp = i;
        while ( iTmp > 9 ){
            iTmp /= DECIMAL;
        }
        int iLowest = i % DECIMAL;
        int iHighest = iTmp;
        // 0があったらスルー
        if(iLowest == 0){ continue; }
        // 同じだったらansに+1 条件にある一桁があるかどうかの確認
        if( iLowest == iHighest ){
            ans += 1;
        }
        // 二桁以上の数に足しこむ
        for (int nDigit = 2; nDigit < 10; nDigit++){
            // ペア候補の数の最大値と最小値を算出
            int pairMin = iLowest * pow(10, nDigit-1) + iHighest;
            int pairMax = pairMin;
            for (int j = 1; j < nDigit-1; j++){
                pairMax += 9*pow(10, j); 
            }
            // n が ペア候補の最大値以上のとき、最大位最小位以外は任意になるので、
            if ( n >= pairMax ){
                ans += pow(10, nDigit-2);
            }
            // nが ペア候補の最大値よりちいさく、ペア候補の最小値より大きい時
            else if ( n >= pairMin && n < pairMax ){
                // n の最大位と最小位を除いた数をansに足す
                int tmp = (n - pairMin) / DECIMAL;
                ans += tmp+1;
                // if (i==2012){
                //     cout << tmp << endl;
                // }
                // // n の最小位が ペア候補の最小値 の最小位以上だったら、ansに+1
                // if (i==2012){
                //     cout << n << n%DECIMAL << iHighest << endl;
                // }
                // if ( n%DECIMAL >= iHighest ){
                //     ans++;
                //     if (i==2012){
                //         cout << "OK" << endl;
                //     }
                // }
                // n の最小位が i の最小位より小さかったら、変動なし
            }
            // nが minより小さい時、追加はない、桁をあげてもペアは増えないので、ループを抜け、次の数に移行
            else{
                // cout << i << ' ' << ans << endl;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
