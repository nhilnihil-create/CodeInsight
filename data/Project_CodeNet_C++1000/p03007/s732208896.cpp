#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 998244353;

const int Cin()
{
    int n;
    cin >> n;
    return n;
}

int main()
{
    int N = Cin();
    vector<int> As(N);
    int nonNegaNum = 0;
    for (auto &Ai : As)
    {
        Ai = Cin();
        if (Ai >= 0) ++nonNegaNum;
    }
    sort(As.begin(), As.end());
    int ans = 0;
    // 負の数が１つもない場合，最小の数A0で引かれるようにする
    // すなわち，A_{N-1}-(A0-A1-...-A_{N-2})とすればよい
    if (nonNegaNum == N)
    {
        ans = As[0];
        for (int i = 1; i < N - 1; ++i) ans -= As[i];
        ans = As[N - 1] - ans;
        cout << ans << endl;
        int prev = As[0];
        for (int i = 1; i <= N - 2; ++i)
        {
            cout << prev << ' ' << As[i] << endl;
            prev -= As[i];
        }
        cout << As[N - 1] << ' ' << prev << endl;
    }
    // 全て負の数のとき，A_{N-1}からそれ以下の数を全て引けば良い
    // すなわち，A_{N-1}-A0-A1-...-A_{N-2}とすればよい
    else if (nonNegaNum == 0)
    {
        ans = As[N - 1];
        for (int i = 0; i <= N - 2; ++i) ans -= As[i];
        cout << ans << endl;
        int prev = As[N - 1];
        for (int i = 0; i <= N - 2; ++i)
        {
            cout << prev << ' ' << As[i] << endl;
            prev -= As[i];
        }
    }
    // ゼロ以上の数がk=(nonNegaNum)個のとき，
    // A0,A1~A_{N-k-1}(={-})が負の数で，A_{N-k}~A_{N-2}(={+}),A_{N-1}がゼロ以上の数
    // このとき，A_{N-1}-(A0-{+})-{-}=A_{N-1}+{+}-{-}-A0とすれば全て正にできて最大
    else
    {
        for (const int &Ai : As) ans += abs(Ai);
        cout << ans << endl;
        int prev = As[0];
        for (int i = N - nonNegaNum; i <= N - 2; ++i)
        {
            cout << prev << ' ' << As[i] << endl;
            prev -= As[i];
        }
        cout << As[N - 1] << ' ' << prev << endl;
        prev = As[N - 1] - prev;
        for (int i = 1; i <= N - nonNegaNum - 1; ++i)
        {
            cout << prev << ' ' << As[i] << endl;
            prev -= As[i];
        }
    }
}
