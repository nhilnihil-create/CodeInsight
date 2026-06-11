#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
typedef long long ll;
#define MOD 1000000007
int main()
{
    int X, N;
    cin >> X >> N;
    vector<bool> p(101);
    for (int i = 0; i < N; ++i)
    {
        int P;
        cin >> P;
        p[P] = true;
    }
    // 下
    int low_memo = 0;
    int high_memo = 0;
    for (int i = X; i > 0; --i)
    {
        if (!p[i])
        {
            low_memo = i;
            break;
        }
    }

    //　上
    for (int i = X; i <= 101; ++i)
    {
        if (!p[i])
        {
            high_memo = i;
            break;
        }
    }
    if (high_memo - X >= X - low_memo)
    {
        cout << low_memo << endl;
    }
    else
    {
        cout << high_memo << endl;
    }
}
