#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,ans;

    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int m = p[0];
    ans = 1;
    for (int i = 1;i < n;++i) {
        if (p[i] <= m) {
            m = p[i];
            ++ans;
        }
    }

    //結果
    std::cout << ans << endl;
}
