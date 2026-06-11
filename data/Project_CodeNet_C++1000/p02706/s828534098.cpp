// ABC163B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> a;
        sum = sum + a;
    }
    if (sum > n) {
        cout << "-1" << endl;
    }
    else {
        cout << n - sum << endl;
    }
}
