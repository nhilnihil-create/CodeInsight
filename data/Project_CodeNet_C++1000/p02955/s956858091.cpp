#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

void solve() {
    long long n, k;
    cin>>n>>k;
    vector < long long > v(n);
    long long sum = 0;
    for (auto &i : v) {
        cin>>i;
        sum += i;
    }
    long long ans = -1;
    for (long long d = 1; d * d <= sum; d++) {
        if (sum % d != 0)
            continue;
        long long dd = sum / d;
        {
            long long curr = 0;
            long long mx = 0;
            vector < long long > a;
            long long sm = 0;
            for (long long i = 0; i < n; i++) {
                a.push_back(v[i] % dd);
                sm += a.back();
            }
            sort(a.rbegin(), a.rend());
            long long pr = 0;
            curr = sm;
            for (int i = 0; i < n; i++) {
                curr = min(curr, max(i * dd - pr, sm));
                pr += a[i];
                sm -= a[i];
            }
            if (curr <= k) {
                cout << dd << "\n";
                return;
            }
        }
        dd = d;
        {
            long long curr = 0;
            long long mx = 0;
            vector < long long > a;
            long long sm = 0;
            for (long long i = 0; i < n; i++) {
                a.push_back(v[i] % dd);
                sm += a.back();
            }
            sort(a.rbegin(), a.rend());
            long long pr = 0;
            curr = sm;
            for (int i = 0; i < n; i++) {
                curr = min(curr, max(i * dd - pr, sm));
                pr += a[i];
                sm -= a[i];
            }
            if (curr <= k) {
                ans = dd;
            }
        }
    }
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    long long t = 1;
    while (t--)
        solve();
}