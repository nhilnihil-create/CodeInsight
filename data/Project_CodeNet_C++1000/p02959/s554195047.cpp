// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

int main()
{
    int n,b;
    int a[100005];
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b;

        if (a[i] >= b) {
            a[i] -= b;
            ans += b;
        }
        else {
            b -= a[i];
            ans += a[i];
            a[i] = 0;
            if (a[i + 1] >= b) {
                a[i + 1] -= b;
                ans += b;
            }
            else {
                b -= a[i + 1];
                ans += a[i + 1];
                a[i + 1] = 0;
            }
           
        }
    }

    cout << ans << endl;
    return 0;

}

