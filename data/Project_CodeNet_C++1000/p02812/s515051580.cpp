#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        if(s.substr(i, 3)=="ABC")
        ++ans;
    }
    cout << ans << endl;
}