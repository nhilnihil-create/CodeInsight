#include<bits/stdc++.h>
using namespace std;

constexpr int MAX = 4e5;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> c(n + 1, 0);
    for(int i = 0; i < n; i++) c[a[i]]++;

    vector<int> d(n + 1, 0);
    for(int i = 1; i < n + 1; i++) d[c[i]]++;

    vector< pair<int64_t, int64_t> > max_len(n + 2, {0, 0});
    max_len[n + 1].first = MAX;
    max_len[n + 1].second = n + 1;
    vector<int64_t> sum_k(n + 1, 0);
    vector<int64_t> sum(n + 1, 0);
    for(int i = 1; i < n + 1; i++) sum[0] += d[i];
    for(int i = 1; i < n + 1; i++) {
        sum_k[i] = sum_k[i - 1] + i * d[i];
        sum[i] = sum[i - 1] - d[i];
    }

    for(int i = 1; i < n + 1; i++) {
        max_len[i].first = (sum_k[i] + i * sum[i]) / i;
        max_len[i].second = i;
    }
    sort(max_len.begin(), max_len.end());

    int point = 1;
    for(int i = 1; i < n + 1; i++) {
        int p = point;
        for(int j = p; j < n + 2; j++) {
            if(max_len[j].first <= i) {
                point++;
            } else {
                if(max_len[j - 1].first >= i) {
                    cout << max_len[j - 1].second << endl;
                } else if(j != n + 1) {
                    cout << max_len[j].second << endl;
                } else {
                    cout << 0 << endl;
                }
                break;
            }
        }
    }

    return 0;
}