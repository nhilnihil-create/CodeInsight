#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ok(int l, vector<int> &a, const int &k) {
    long long sum = 0;
    for (auto x: a) sum += (x-1) / l;
    if (sum > k) return false;
    else return true;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int top = 1e9, bottom = 0;
    while (top - bottom > 1) {
        int mid = (top + bottom) / 2;
        if (ok(mid, a, k)) top = mid;
        else bottom = mid;
    }
    cout << top << endl;
    return 0;
}