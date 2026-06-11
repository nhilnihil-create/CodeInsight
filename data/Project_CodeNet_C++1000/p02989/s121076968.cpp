// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int dMax = 100'100;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    sort(all(d));
    int left = n / 2 - 1;
    int right = n / 2;
    int ans = 0;
    for (int i = d[left] + 1; i <= d[right]; i++)
        ans++;
    cout << ans << endl;
}

int main()
{
    // srand((unsigned)time(NULL));
    // int t = clock();
    solve();
    // double et = 1.0 * (clock() - t) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}