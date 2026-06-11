#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep (i, n) cin >> p[i];
    rep (i, n) cin >> q[i];
    vector<int> one_case;

    for (int i = 1; i <= n; i++) one_case.emplace_back(i);

    int a = 0, b = 0;
    int cnt = 0;
    do {
        int i = 0, aflag = 0, bflag = 0;
        cnt++;
        for (auto num : one_case) {
            if (num == p[i]) aflag++;
            if (num == q[i]) bflag++;
            i++;
        }
        if (aflag == n) a = cnt;
        if (bflag == n) b = cnt;
    } while (next_permutation(one_case.begin(), one_case.end()));

    cout << abs(a-b) << endl;
    return 0;
}