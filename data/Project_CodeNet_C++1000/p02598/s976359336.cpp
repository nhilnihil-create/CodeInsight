#include<bits/stdc++.h>
using namespace std;
const int mx = 1e6;
int n, k;
vector<int>v;
bool chk(int mid) {
    int temp = k;
    if (mid == 0)
        return false;
    for (int i(0); i < n; ++i) {
        if (v[i] <= mid)continue;
        int cnt = v[i] / mid;
        temp -= cnt;
    }
    return temp >= 0;
}
int main() {
    cin >> n >> k;
    v.resize(n);
    for (auto& x : v)
        cin >> x;
    int l = -1, r = 1e9 + 5;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (chk(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
}