#include <iostream>
#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 1000010
#define vi vector<int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vi v1(n), v2(n);
    for(auto &x : v1){
        cin >> x;
    }
    for(auto &x : v2){
        cin >> x;
    }
    int sum = 0;
    double max = -MAXN;
    for (int i = 0; i < n; ++i) {
        double val = fabs(v1[i] - v2[i]);
        if(val > max) max = val;
        sum += val;
    }
    double sum1 = 0;
    for (int i = 0; i < n; ++i) {
        sum1 += pow(v1[i] - v2[i], 2);
    }
    double sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum2 += pow(fabs(v1[i] - v2[i]), 3);
    }
    auto p1 = sqrt(sum1);
    auto pp = cbrt(sum2);
    double tt = (1.0/3.0);
    double p2 = pow(sum2, tt);


    printf("%.*lf\n", 6, (double)sum);
    printf("%.*lf\n", 6, p1);
    printf("%.*lf\n", 6, pp);
    printf("%.*lf\n", 6, (double)max);
    return 0;
}

