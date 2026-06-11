#include <iostream>
#include<map>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示

using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int N;cin >> N;
    cout << fixed << setprecision(15) << (float)(N - N / 2) /  N << endl;
    return 0;
}