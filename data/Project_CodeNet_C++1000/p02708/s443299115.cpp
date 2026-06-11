// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;
int main()
{
    int n, k;

    cin >> n >> k;

    long long  sum = 0;
    for (long long  i = k; i <= n + 1; i++) {
        sum += (i*(2 * n - i + 1) - (i - 1) * i) / 2 + 1;

       
    }
    sum = sum % (1000000000 + 7);
    cout << sum << endl;
}

