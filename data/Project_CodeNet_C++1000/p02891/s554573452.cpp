#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

bool ContainsSameChar(const string &S)
{
    for (const char ch : S)
    {
        if (ch != S.front()) return false;
    }
    return true;
}

int main()
{
    string S; int K; cin >> S >> K;
    if (ContainsSameChar(S))
    {
        cout << S.length() * K / 2 << endl;
    }
    else
    {
        // S内部で必要な書き換え回数を数える
        LLONG inside = 0;
        for (int i = 0; i < S.length() - 1; ++i)
        {
            if (S[i] == S[i + 1])
            {
                ++inside;
                ++i;
            }
        }
        // つなぎ目で必要な書き換え数を数える
        LLONG ans = inside * K;
        if (S.front() == S.back())
        {
            LLONG frontNum = 1, backNum = 1;
            for (int i = 1; i < S.length(); ++i)
            {
                if (S[i] == S.front()) ++frontNum;
                else break;
            }
            for (int i = 1; i < S.length(); ++i)
            {
                if (S[S.length() - i - 1] == S.back()) ++backNum;
                else break;
            }
            ans -= (frontNum / 2 + backNum / 2 - (frontNum + backNum) / 2) * (K - 1);
        }
        cout << ans << endl;
    }
}
