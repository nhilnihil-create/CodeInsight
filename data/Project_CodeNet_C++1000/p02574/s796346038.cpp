#include <bits/stdc++.h>
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.rbegin(), a.rend());
    vector<int> pfactor(a[0] + 1, -1);
    pfactor[1] = 1;
    for (int i = 2; i <= a[0]; i++) {
        if (pfactor[i] != -1) continue;
        int k = i;
        while (k <= a[0]) {
            if (pfactor[k] == -1) {
                pfactor[k] = i;
            }
            k += i;
        }
    }
    unordered_map<int, int> m;
    bool coprime = true;
    for (int t : a) {
        int temp = 1;
        while (t > 1) {
            if (pfactor[t] != temp) {
                m[pfactor[t]]++;
                if (m[pfactor[t]] > 1) {
                    coprime = false;
                }
                if (m[pfactor[t]] == n) {
                    cout << "not coprime" << endl;
                    return 0;
                }
            }
            temp = pfactor[t];
            t = t / temp;
        }
    }
    if (coprime) {
        cout << "pairwise coprime" << endl;
    } else {
        cout << "setwise coprime" << endl;
    }
    return 0;
}