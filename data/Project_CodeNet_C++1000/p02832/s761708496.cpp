// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[200005];
    int ans=0;
    int cnt = 1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == cnt) {
            cnt++;
        }
        else {
            ans++;
        }
    }

    if (cnt == 1) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }


    
}

