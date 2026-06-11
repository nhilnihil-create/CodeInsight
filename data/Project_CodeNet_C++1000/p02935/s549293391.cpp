#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (size_t i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    double ans = v[0];
    for (size_t i = 1; i < n; i++) {
        ans = (double)(ans + v[i])/2;
    }

    printf("%.10f\n", ans);
    return 0;
}
