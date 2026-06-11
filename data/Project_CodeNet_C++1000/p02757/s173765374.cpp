#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 58;
const int MOD = 1000000007;
const int MAX_N = 200100;

int counter[10000];
signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    REP(i, P)
    {
        counter[i] = 0;
    }

    if (P == 2)
    {
        int ans = 0;
        REP(i, N)
        {
            int c = S[i] - '0';
            if (c % 2 == 0)
            {
                ans += i + 1;
            }
        }
        cout << ans << endl;
    }
    else if (P == 5)
    {
        int ans = 0;
        REP(i, N)
        {
            int c = S[i] - '0';
            if (c == 0 || c == 5)
            {
                ans += i + 1;
            }
        }
        cout << ans << endl;
    }
    else
    {
        int ten = 1;
        int tmp = 0;
        for (int i = 1; i <= N; ++i)
        {
            int c = S[N - i] - '0';
            tmp += ten * c;
            tmp %= P;
            counter[tmp]++;
            ten *= 10;
            ten %= P;
        }
        int ans = 0;
        REP(i, P)
        {
            if (i == 0)
            {
                ans += counter[i];
            }
            if (counter[i] > 1)
                ans += (counter[i] * (counter[i] - 1) / 2);
        }
        cout << ans << endl;
    }

    return 0;
}