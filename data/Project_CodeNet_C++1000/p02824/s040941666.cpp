#include <algorithm>
#include <iostream>
using namespace std;
int n, m, v, p; 

bool check(int *a, int i) {
    if (a[i] + m < a[n-p]) return false;
    else if (v <= i+p) return true;
    long long amt = (long long)m * (v - (i + p));
    for (int j = i+1; j <= n-p; j++) {
        if (a[i] + m < a[j]) return false;
        amt -= a[i] + m - a[j];
        if (amt <= 0) return true;
    }
    return false;
}

int main() {
    cin >> n >> m >> v >> p;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int lb = -1, ub = n-p;
    while (ub - lb > 1) {
        int i = (ub + lb) / 2;
        if (check(a, i)) ub = i;
        else lb = i;
    }
    cout << n-ub << endl;
}
