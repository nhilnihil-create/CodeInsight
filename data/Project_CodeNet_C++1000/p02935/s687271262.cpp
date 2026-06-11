#include <bits/stdc++.h>
using namespace std;

double f(vector<int> v, int i) {
    if (i + 1 == (int)v.size()) return v.at(i);
    return (f(v, i + 1) + v.at(i)) / 2;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end(), greater<int>());
    printf("%.6lf", f(v, 0));
    return 0;
}