// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    int p[21];
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }


    for (int i = 1; i < n - 1; i++) {
        if (p[i - 1] < p[i] && p[i] < p[i + 1]) {
            cnt++;
        }
        else if (p[i - 1] > p[i] && p[i] > p[i + 1]) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}

