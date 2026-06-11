#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const int mod = 1e9 + 7;
using ll = long long;

int main()
{
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    for (ll i = 0; i < n - 2; i++)
    {
        string a = s.substr(i, 3);
        if (a == "ABC")
        {
            ans++;
            i += 2;
        }
    }

    cout << ans << endl;
    return 0;
}