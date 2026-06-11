#include <bits/stdc++.h>
using namespace std;
int calc(int m) {
    if (m == 0) return 1;
    return m * calc(m - 1);
}
int main() {
    int n;
    cin >> n;
    vector<int> X, Y;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    double sum_dist = 0;
    vector<int> perm;
    for (int i = 0; i < n; i++) perm.push_back(i);
    do {
       for (int i = 0; i < n - 1; i++) {
           int dx = X[perm[i+1]] - X[perm[i]];
           int dy = Y[perm[i+1]] - Y[perm[i]];
           sum_dist += sqrt(dx * dx + dy * dy);
       }  
    } while (next_permutation(perm.begin(), perm.end()));
    double ave = sum_dist / calc(n);
    printf("%.10f\n", ave);
    return 0;
}