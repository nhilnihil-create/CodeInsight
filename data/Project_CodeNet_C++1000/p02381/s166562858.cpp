#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

int main() {
    int n;

    while (1) {
        cin >> n;
        if (n == 0) break;

        int s[n]={};
        REP(i, n) cin >> s[i];
        int sum = 0;
        REP(i, n) sum += s[i];
        double ave = 1.0 * sum / n;
        double dist = 0;
        REP(i, n) dist += (ave - s[i]) * (ave - s[i]);
        printf("%lf\n", sqrt(dist / n));
    }
}