#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    string ans;
    if (S == "Sunny") ans = "Cloudy";
    else if (S == "Cloudy") ans = "Rainy";
    else ans = "Sunny";
    cout << ans << endl;
}