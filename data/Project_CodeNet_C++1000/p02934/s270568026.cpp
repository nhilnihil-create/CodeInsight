// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    double a;
    cin >> n;

    double sum = 0;
    double multi = 1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += 1 / a;
    }
    double ans = 1 / sum;
    printf("%.10f",ans);
}

