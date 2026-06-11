/**
*    author:  Dooloper
*    created: 12.09.2020 21:54:51
**/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <functional>
#include <cassert>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define PI 3.14159265358979323846264338327950L

int main()
{
    int D, T, S;
    cin >> D >> T >> S;
    double Time = (double)D / S;

    if (T >= Time)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     //入力を受け取る
//     int D, T, S;
//     cin >> D >> T >> S;

//     //高橋君の移動時間を計算する
//     double time = (double)D / S;

//     //Tとtimeの大小関係に応じて出力をする
//     if (T >= time)
//     {
//         cout << "Yes" << endl;
//     }
//     else
//     {
//         cout << "No" << endl;
//     }
// }
