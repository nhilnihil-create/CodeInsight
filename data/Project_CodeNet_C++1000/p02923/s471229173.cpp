#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    ll n;
    cin >> n;
    int input[n];
    rep0(i, n)
    {
        cin >> input[i];
    }
    int res = 0;
    int tmpRes = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (input[i] >= input[i + 1])
        {
            tmpRes++;
        }
        else
        {
            if (tmpRes >= res)
            {
                res = tmpRes;
            }
            tmpRes = 0;
        }
    }
    if (tmpRes >= res)
    {
        res = tmpRes;
    }
    cout << res << endl;
}
