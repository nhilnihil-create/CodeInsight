// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;
int main()
{
    
    long long h;
    cin >> h;
    long long ans = 0;
    long long cnt = 1;
    while (h > 1) {
        h = h / 2;
        ans += cnt;
        cnt*=2;
    }
    ans += cnt;
    cout << ans << endl;

    return 0;
}

