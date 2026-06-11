#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    string ans;
    if (s == "Sunny")
        ans = "Cloudy";
    if (s == "Cloudy")
        ans = "Rainy";
    if (s == "Rainy")
        ans = "Sunny";
    cout << ans << endl;
    return 0;
}