#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using P = pair<int, int>;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<P> res;
    if (N % 2) // 奇数の時はすんなりと構成できる
    {
        for (int l = 1, r = N-1; l < r; ++l, --r)
        {
            res.emplace_back(l, r);   
        }
    }
    else // 偶数の時は途中で規則を切り替える必要がある
    {
        bool flag = false;
        for (int l = 1, r = N-1; l < r; ++l, --r)
        {
            if (!flag && r - l<= N / 2)
            {
                --r;
                flag = true;
            }
            res.emplace_back(l, r);
        }
    }
    for (int i = 0; i < M; ++i)
    {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}
