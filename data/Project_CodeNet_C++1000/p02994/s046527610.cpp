// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

int main()
{
    int n, l;

    cin >> n >> l;

    int saigo = n + l - 1;
    int ans = 0;
    if (l > 0) {
        for (int i = 1; i < n; i++) {
            ans += l + i;
        }
    }
    else {
        if (saigo >= 0) {
            for (int i = 0; i < n; i++) {
                ans += l + i;
            }
        }
        else {
            for (int i = 0; i < n - 1; i++) {
                ans += l + i;
            }
        }
    }
    cout << ans << endl;
}
