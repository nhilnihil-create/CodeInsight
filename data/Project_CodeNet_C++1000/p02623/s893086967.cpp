#include <bits/stdc++.h>

using namespace std;

vector<int> next_int_vector(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v.at(i);
    }
    return v;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a = next_int_vector(n);
    vector<int> b = next_int_vector(m);

    vector<long> a_cum(n + 1), b_cum(m + 1);
    a_cum[0] = 0;
    b_cum[0] = 0;
    for (int i = 0; i < n; ++i) {
        a_cum.at(i + 1) = a_cum.at(i) + a.at(i);
    }
    for (int i = 0; i < m; ++i) {
        b_cum.at(i + 1) = b_cum.at(i) + b.at(i);
    }

    int max = 0;
    for (int i = 0; i <= n; ++i) {
        long a_sum = a_cum.at(i);
        if (k < a_sum) continue;
        int b_count = distance(b_cum.begin(), --upper_bound(b_cum.begin(), b_cum.end(), k - a_sum));

        int count = i + b_count;
        if (max < count) {
            max = count;
        }
    }
    cout << max << endl;
}
