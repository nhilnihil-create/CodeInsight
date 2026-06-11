// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;
int main()
{
    bool wareru = false;
    int L, R,sa1,sa2,syou;
    int min = 3000;
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        if (i % 2019 == 0) {
            wareru = true;
            break;
        }
        //syou = i / 2019;
        //sa1 = i - 2019 * syou;
        //sa2 = 2019 - i + 2019 * syou;
        //if (sa1 < sa2) {
        //    if (min > sa1) {
        //        min = sa1;
        //    }
        //}
        //else {
        //    if (min > sa2) {
        //        min = sa2;
        //    }
        //}
    }


    if (wareru) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = L; i < R; i++) {
        for (int j = i + 1; j <= R; j++) {
            int x = i % 2019;
            int y = j % 2019;
            int syou = (x * y) % 2019;
            if (syou < min)min = syou;
        }
    }
    cout << min << endl;
    return 0;
}

