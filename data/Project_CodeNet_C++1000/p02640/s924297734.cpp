#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string YES = "Yes";
const string NO = "No";

void solve(long long X, long long Y)
{
    // a + b = X (a>0, b>0)
    //2a + 4b = Y (a>0, b>0)
    //2(X-b) + 4b = Y
    //2X + 2b = Y
    for (ll b = 0; b <= X; b++)
    {
        if (2 * X + 2 * b == Y)
        {
            cout << YES << endl;
            return;
        }
    }
    cout << NO << endl;
}

signed main()
{
    long long X;
    scanf("%lld", &X);
    long long Y;
    scanf("%lld", &Y);
    solve(X, Y);
    return 0;
}
