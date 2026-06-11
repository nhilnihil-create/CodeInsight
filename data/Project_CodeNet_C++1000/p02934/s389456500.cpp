#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> a(n);
    double ans = 0;
    for (size_t i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans += 1/(double)a;
    }
    ans = 1/ans;
    printf("%.10f\n", ans);
    return 0;
}
