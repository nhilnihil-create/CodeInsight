#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    map<int64_t, int64_t>d;
    vector<int64_t>vec(N);
    for (int64_t i=0; i<N; i++) {
        int64_t n;
        cin >> n;
        vec[i] = n;
        if (d.count(n) > 0) {
            d[n] = d[n] + 1;
        } else {
            d[n] = 1;
        }
    }

    int64_t default_comb_count = 0;
    for (auto n : d) {
        if (n.second >= 2) {
            int64_t num = n.second;
            default_comb_count += num * (num - 1) / 2;
        }
    }

    for (int64_t i=0; i<N; i++) {
        int64_t num = vec[i];
        int64_t comb_cunt = default_comb_count;
        if (d[num] >= 2) {
            comb_cunt -= (d[num] * (d[num] - 1) / 2);
        }

        if (d[num] > 2) {
            comb_cunt += ((d[num] -1) * (d[num] - 2) / 2);
        }

        cout << comb_cunt << endl;
    }
    return 0;
}