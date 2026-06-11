#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    string S, T;
    cin >> S >> T;
    int ans = 0;
    for (int i = 0; i < 3; i++)
        if (S[i] == T[i])
            ans++;
    cout << ans;
}