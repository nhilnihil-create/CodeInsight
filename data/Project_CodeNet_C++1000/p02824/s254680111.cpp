#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long m, v, p;
    cin >> n >> m >> v >> p;
    vector<long long> a(n);
    for (auto& e : a) cin >> e;
    sort(a.rbegin(), a.rend());
    
    auto f = [&] (int id) -> bool {
        if (a[id] + m < a[p-1]) return false;
        long long s = a[id]+m, ps = v*m;
        for (int i = 0; i < n; i++) {
            if (i < p-1 || i >= id) ps -= m;
            else ps -= max(0LL, s-a[i]);
        }
        return ps <= 0;
    };
    
    int ok = 0, ng = n;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (f(mid)) ok = mid;
        else ng = mid;
    }
    
    cout << ++ok << endl;
    return 0;
}