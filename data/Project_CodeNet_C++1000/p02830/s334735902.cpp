#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string ans;
    rep(i,n) {
        putchar(s[i]);
        putchar(t[i]);
    }
    putchar('\n');
}