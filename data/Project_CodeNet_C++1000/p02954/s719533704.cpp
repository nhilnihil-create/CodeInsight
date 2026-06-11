#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

// TLE
// 'RL'で最終的に子どもたちが集まる。RLの間隔の単体RとLの数を数え上げて、RとLの箇所にそれぞれ行く場所に足してあげる。

int main(void)
{
    string S;
    cin >> S;

    int N = S.size();
    int R = 0;
    int L = 0;
    vector<int> ans(N, 1);

    // Rの部分を反映
    for (int i = 0; i < N - 1; i++)
    {
        if (S[i] == 'R' && S[i + 1] != 'L')
        {
            R++;
            ans[i] -= 1;
        }

        if (S[i] == 'R' && S[i + 1] == 'L')
        {
            int add = R / 2;
            if (R % 2 == 0)
            {
                ans[i] += add;
                ans[i + 1] += add;
            }
            else
            {
                ans[i] += add;
                ans[i + 1] += add + 1;
            }
            // init R
            R = 0;
        }
    }

    // Lの部分を反映
    reverse(S.begin(), S.end());
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < N - 1; i++)
    {
        if (S[i] == 'L' && S[i + 1] != 'R')
        {
            L++;
            ans[i] -= 1;
        }

        if (S[i] == 'L' && S[i + 1] == 'R')
        {
            int add = L / 2;
            if (L % 2 == 0)
            {
                ans[i] += add;
                ans[i + 1] += add;
            }
            else
            {
                ans[i] += add;
                ans[i + 1] += add + 1;
            }
            // init L
            L = 0;
        }
    }
    reverse(ans.begin(), ans.end());

    //debug
    for (int i = 0; i < N; i++)
    {
        printf("%d", ans[i]);
        if (i != N - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    return (0);
}