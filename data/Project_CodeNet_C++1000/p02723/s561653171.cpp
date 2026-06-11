#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    if (s[2] == s[3] && s[4] == s[5])
        puts("Yes");
    else
        puts("No");
}