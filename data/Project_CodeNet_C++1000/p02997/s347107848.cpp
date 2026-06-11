#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;

int main()
{
    int N, K;
    cin >> N >> K;
    // 距離2のペアは最大でも(N-1)(N-2)/2組しかつくれない
    if (K > (N - 1) * (N - 2) / 2)
    {
        cout << -1 << endl;
        return 0;
    }
    // 1つの頂点から(N-1)頂点へと結ぶとペア数は(N-1)(N-2)/2
    // そこからペア数がKになるまで(N-1)頂点間を結んでいく
    int rem = (N - 1) * (N - 2) / 2 - K;
    // M = (N-1) + rem
    cout << N - 1 + rem << endl;
    // 1つの頂点(番号1)から残りの(N-1)頂点へと結ぶ
    for (int i = 2; i <= N; ++i)
    {
        cout << 1 << ' ' << i << endl;
    }
    // 残りの(N-1)頂点間をrem本だけ結ぶ
    for (int i = 2; i <= N; ++i)
    {
        if (rem == 0) break;
        for (int j = i + 1; j <= N; ++j)
        {
            cout << i << ' ' << j << endl;
            --rem;
            if (rem == 0) break;
        }
    }
}
