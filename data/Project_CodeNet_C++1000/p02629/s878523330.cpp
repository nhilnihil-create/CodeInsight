#include <bits/stdc++.h>

#define debug(s) cout << s << endl
#define debug1(s, t) cout << s << " " << t << endl
#define debug2(s, t, u) cout << s << " " << t << " " << u << endl
#define printvec(v)       \
    for (auto &&i : v)    \
        cout << i << " "; \
    cout << endl
#define rep(n, i) for (int i = 0; i < n; i++)

using namespace std;
using i64 = long long;

int main()
{
    int MAX_ALPHABET = 11;
    vector<i64> basis(MAX_ALPHABET + 1);
    for (int i = 0; i < basis.size(); i++)
    {
        basis[i] = pow(26, i);
    }

    i64 n;
    cin >> n;

    // 26進表記
    vector<int> vec;
    for (int i = basis.size() - 1; i >= 0; i--)
    {
        vec.push_back(n / basis[i]);
        n %= basis[i];
    }

    // 0を含まないように変形
    for (int j = 0; j < vec.size(); j++)
    {
        bool inRealDigit = false;
        for (int i = 0; i < vec.size(); i++)
        {
            if (!inRealDigit)
            {
                inRealDigit = vec[i] != 0;
                continue;
            }

            if (vec[i] == 0)
            {
                vec[i - 1]--;
                vec[i] = 26;
            }
        }
    }

    // 文字列に変換
    string name;
    for (auto &&d : vec)
    {
        if (d != 0)
        {
            name.push_back('a' + d - 1);
        }
    }

    cout << name << endl;

    return 0;
}
