#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    double p, sum = 0., ans = 0.;
    queue<double> q;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        p = (p+1.)/2.;
        sum += p;
        q.push(p);
        if (i >= k) {
            ans = max (ans, sum);
            sum -= q.front();
            q.pop();
        }
    }
    printf("%.7lf", ans);
}