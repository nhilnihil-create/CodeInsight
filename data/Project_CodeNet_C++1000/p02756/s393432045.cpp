#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for (int i = (m); i < (int)(n); i++)

int main()
{
    string S;
    char c;
    int Q, T, F, N, direct = 1;
    cin >> S;
    N = S.length();
    cin >> Q;
    deque<char> res;
    REP(i, N)
    {
        res.push_back(S[i]);
    }

    REP(i, Q)
    {
        cin >> T;
        if (T == 1)
        {
            direct ^= 1;
        }
        else
        {
            cin >> F;
            cin >> c;
            if ((F - 1) ^ direct)
            {
                res.push_front(c);
            }
            else
            {
                res.push_back(c);
            }
        }
    }

    if (direct)
    {
        while (res.size())
        {
            cout << res.front();
            res.pop_front();
        }
    }
    else
    {
        while (res.size())
        {
            cout << res.back();
            res.pop_back();
        }
    }
    cout << endl;
}