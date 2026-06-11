// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    long long x, k, d;

    cin >> x >> k >> d;

    if (abs(x) /d> k ) {
        cout << abs(x) - k * d << endl;
       
    }
    else {
        long long a = abs(x) % d;
        long long b = abs(x) / d;

        if ((k - b) % 2 == 0) {
            cout << abs(x)-b*d << endl;
        }
        else {
            cout << d - (abs(x) - b * d) << endl;
        }
    }
  //  cout << 1000000000000*2200000000000 << endl;

    return 0;
}

