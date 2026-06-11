// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;

int a[100005];
int m = 0;
int sum = 0;
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; i++) {
        if (a[i] >= a[i + 1]) {
            sum++;
            if (m < sum) {
                m = sum;
            }
        }

        else {
            if (m < sum) {
                m = sum;
            }
            sum = 0;
        }
    }

    cout << m << endl;
    return 0;
}
