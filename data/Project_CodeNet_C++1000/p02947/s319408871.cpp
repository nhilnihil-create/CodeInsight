#include <bits/stdc++.h>
#define int long long
#define pq priority_queue

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> anag;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (anag.find(s) != anag.end()) {
            anag[s]++;
        } else {
            anag[s] = 1;
        }
    }
    int no_pairs = 0;
    for (map<string, int>::iterator it = anag.begin(); it != anag.end(); it++) {
        no_pairs += (it -> second) * ((it -> second) - 1) / 2;
    }
    cout << no_pairs;
}