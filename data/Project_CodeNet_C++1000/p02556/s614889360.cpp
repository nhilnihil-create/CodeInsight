#include<bits/stdc++.h>
using namespace std;

int main() { 
    int N;
    cin >> N;
    int x[N], y[N];
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    int mx_xpy = -2e9, mn_xpy = 2e9, mx_xmy = -2e9, mn_xmy = 2e9;
    for (int i = 0; i < N; i++) {
        mx_xpy = max(mx_xpy, x[i] + y[i]);
        mn_xpy = min(mn_xpy, x[i] + y[i]);
        mx_xmy = max(mx_xmy, x[i] - y[i]);
        mn_xmy = min(mn_xmy, x[i] - y[i]);
    }

    cout << max(mx_xpy - mn_xpy, mx_xmy - mn_xmy) << endl;
    return 0;
}