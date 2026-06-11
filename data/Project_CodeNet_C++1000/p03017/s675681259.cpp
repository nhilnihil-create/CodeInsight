#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;

    bool isPossible = true;
    for (ll i = A; i < C - 1; ++i)
    {
        if (S[i] == '#')
        {
            if (i + 1 < C - 1 && S[i + 1] == '#')
            {
                isPossible = false;
                break;
            }
        }
    }
    if (isPossible)
    {
        for (ll i = B; i < D - 1; ++i)
        {
            if (S[i] == '#')
            {
                if (i + 1 < D - 1 && S[i + 1] == '#')
                {
                    isPossible = false;
                    break;
                }
            }
        }
    }
    if (isPossible)
    {
        if (C > D)
        {
            bool flag = false;
            for (ll i = B - 1; i < D; ++i)
            {
                if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.')
                {
                    flag = true;
                    break;
                }
            }
            isPossible = flag;
        }
    }
    string ans = isPossible ? "Yes" : "No";

    cout << ans << endl;
}
