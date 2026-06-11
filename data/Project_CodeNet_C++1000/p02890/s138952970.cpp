//#include <iostream>
//#include <vector>
//#include <set>
//#include <map>
//#include <algorithm>

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll len = 2 * (int) 1e5 + 1;

ll n, m, l;
ll from, to, cost, tmp;

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a[tmp - 1]++;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    while (a.back() == 0) {
        a.pop_back();
    }

    reverse(a.begin(), a.end());
    vector<int> ps(a.size(), 0);
    ps[0] = a[0];

    for (int i = 1; i < a.size(); i++) {
        ps[i] = ps[i - 1] + a[i];
    }
    int need = n;

    for (int i = 0; i < n; i++) {
        while (true) {
            int l = 0, r = a.size() - 1, mid;
            while (l < r) {
                mid = (l + r) / 2;
                if (a[mid] < need) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
//            cout << need << " bin " << l << endl;
            ll sum = 0;
            if (a[r] >= need && r > 0) {
                sum += ps[r - 1];
            } else {
                if (a[r] < need && r > 0) {
                    sum += ps[r];
                }
            }
            if (a[r] >= need) {
                sum += (a.size() - r) * need;
            }
//            cout << "sum" << sum << endl;
            if (sum < (i + 1) * need) {
                need--;
            } else {
                break;
            }
        }
        cout << need << "\n";
    }
}
