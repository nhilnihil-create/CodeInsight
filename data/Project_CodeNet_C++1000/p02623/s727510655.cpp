#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <map>

// #pragma GCC optimize ("O3")

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; long long k; cin >> n >> m >> k;
    vector<long long> a(n);
    vector<long long> b(m);
    // vector<long long> sum_a(n+1);
    // vector<long long> sum_b(m+1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    // sum_a[0] = 0;
    // sum_b[0] = 0;
    // for (int i = 1; i < n+1; i++) sum_a[i] = sum_a[i-1] + a[i-1];
    // for (int i = 1; i < m+1; i++) sum_b[i] = sum_b[i-1] + b[i-1];

    // int lower_a = 0;
    // int lower_b = 0;
    // for (int i = 0; i < n; i++)
    //     if (sum_a[i] <= k)
    //         lower_a = i;
    // for (int i = 0; i < m; i++)
    //     if (sum_b[i] <= k)
    //         lower_b = i;
    // if (lower_a == 0 && lower_b == 0) {
    //     cout << 0;
    //     return 0;
    // }
    int out = 0;
    long long sum_sofar = 0;
    for (int i = 0; i < n; i++) {
        if (sum_sofar + a[i] <= k) {
            sum_sofar += a[i];
            out++;
        }
        else {
            break;
        }
    }
    int low = out - 1;
    // cout << low << " ";
    // sum = sum_a[out];
    int max_out = out;
    for (int j = 0; j < m; j++) {
        if (sum_sofar + b[j] <= k) {
            sum_sofar += b[j];
            out++;
            max_out = max(out, max_out);
            // cout << out << " ";
        }
        else {
            while (low >= 0 && sum_sofar + b[j] > k) {
                sum_sofar -= a[low];
                low--;
                out--;
                // cout << sum_sofar << " ";
            }
            if (sum_sofar + b[j] <= k) {
                sum_sofar += b[j];
                out++;
                max_out = max(out, max_out);
                // cout << sum_sofar << " ";
            } else {
                break;
            }
        }
    }
    cout << max_out;

    // int out1 = 0;
    // int remain = k - sum_a[lower_a];
    // int i = 0;
    // while (i < sum_b.size() && sum_b[i] <= remain) {
    //     i++;
    // }
    // out1 = lower_a + i +1;

    // int out2 = 0;
    // remain = k - sum_b[lower_b];
    // i = 0;
    // while (i < sum_a.size() && sum_a[i] <= remain) {
    //     i++;
    // }
    // out2 = lower_b + i +1;
    // cout << max(out2, out1);


}