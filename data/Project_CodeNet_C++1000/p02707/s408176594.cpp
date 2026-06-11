#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define ALL(n) begin(n), end(n)
using ll = long long;

#define MAX 2 * 1000005

int main()
{
    int n;
    cin >> n;
    vector<int> l(MAX, 0);
    n;
    rep(i, n - 1)
    {
        int a;
        cin >> a;
        // 社員番号 a の人の数を計測
        l[a]++;
    }
    rep(i, n) { cout << l[i + 1] << endl; }

    return 0;
}