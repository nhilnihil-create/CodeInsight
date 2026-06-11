/*
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_10_C
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

int
main()
{
    ios::sync_with_stdio(false);

    cout << setprecision(8) << fixed;
    while (true) {
        int n;
        cin >> n; cin.ignore();

        if (n == 0) { break; }
        vector<double> S(n);
        for (int i = 0; i < n; i++) {
            cin >> S[i]; cin.ignore();
        }
        double m = accumulate(S.cbegin(), S.cend(), 0.0) / n;

        for_each(S.begin(), S.end(), [&](double &x) mutable { x = (x - m) * (x - m); });
        cout << sqrt( accumulate(S.cbegin(), S.cend(), 0.0) / n) << endl;
    }

    return 0;
}