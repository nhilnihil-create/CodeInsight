#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define endl '\n'
#define lli long long int
#define rep(i, s, e) for (int i = s; i < e; i++)

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> R, G, B;
    rep(i, 0, N)
    {
        switch (S[i])
        {
        case 'R':
            R.push_back(i);
            break;
        case 'G':
            G.push_back(i);
            break;
        case 'B':
            B.push_back(i);
            break;
        default:
            break;
        }
    }
    const int res = R.size() * G.size() * B.size();
    unsigned int even = 0;
    for (int r : R)
    {
        const int rr = 2 * r;
        for (int g : G)
        {
            const int gg = 2 * g;
            int rg = r + g;
            for (int b : B)
            {
                const int bb = 2 * b;
                const int br = b + r;
                const int bg = b + g;
                // r<g<b
                if (gg == br || bb == rg || rr == bg)
                    even++;
            }
        }
    }
    cout << res - even << endl;
}