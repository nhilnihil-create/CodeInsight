#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 60; //10e18+10e17ちょっとくらい
const int MOD = 1000000007;
const int MAX_N = 200100;

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 2; i < min((int)1e7, n); i++)
    {
        int t = n;
        while (t % i == 0)
        {
            t /= i;
        }
        if (t % i == 1)
        {
            ans++;
        }
    }

    for (int i = 1; i <= min((int)1e7, n - 1); i++)
    {
        int t = n - 1;
        if (t % i == 0)
        {
            if ((n - 1) / i > min((int)1e7, n))
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}