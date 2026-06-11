// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

long long  gcd(long long  a, long long b) {

 //   if (a < b)swap(a, b);
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

int main()
{
    long long a, b, c, d;

    cin >> a >> b >> c >> d;
    //cout << gcd(2, 8);

    long long l = (a - 1) / c;
    long long r = b / c;
    long long kosuu1 = r - l;

    long long l2 = (a - 1) / d;
    long long r2 = b / d;
    long long kosuu2 = r2 - l2;

    long long sk = lcm(c, d);
   // cout << sk << endl;

    long long l3 = (a - 1) / sk;
    long long r3 = b / sk;
    long long kosuu3 = r3 - l3;

    cout << (b-a+1)-(kosuu1 + kosuu2 - kosuu3) << endl;
    return 0;


}

