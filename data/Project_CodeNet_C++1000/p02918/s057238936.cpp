#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int a = 0;
    rep(i, n - 1)
    {
        if (s[i] != s[i + 1])
            a++;
    }
    cout << n - 1 - max(a - 2 * k, 0) << endl;
}