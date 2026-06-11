// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

int main()
{
    int n, d;

    cin >> n>>d;

    int x[10][10];
    int kyori2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> x[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            kyori2 = 0;
            bool ok = false;
            for (int k = 0; k < d; k++) {
                kyori2+= (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            int x = 0;
            while (x*x<=kyori2) {
                if (x * x == kyori2)ok = true;
                x++;
            }
            if (ok)ans++;
           
        }
    }
    cout << ans << endl;
}

