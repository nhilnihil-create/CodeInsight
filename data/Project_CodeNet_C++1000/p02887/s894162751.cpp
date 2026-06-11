#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n;
    string s,ans;

    cin >> n >> s;

    ans = "";
    rep(i,n-1) {
        if (s[i] != s[i + 1]) {
            ans += s[i];
        }
    }
    ans += s[n];

    std::cout << ans.size() << endl;

    return 0;
}
