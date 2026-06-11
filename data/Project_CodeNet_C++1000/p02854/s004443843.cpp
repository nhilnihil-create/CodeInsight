#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, all=0; cin >>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i); all+=a.at(i);
    }
    long long ret = all, tmp = 0;
    for (int i = 0; i < n; i++) {
        tmp += a.at(i);
        all -= a.at(i);
        ret = min(ret, abs(tmp-all));
    }
    cout << ret << endl;
    return 0;
}