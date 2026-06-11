// https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long H, W;
    cin >> H >> W;

    cout << (H == 1 | W == 1 ? 1 : (H * W + 1) / 2) << endl;
    return 0;
}
