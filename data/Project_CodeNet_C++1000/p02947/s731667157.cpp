#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int64_t cx(int64_t i) {
    int64_t res = 1;
    while (i > 1) {
        res = res * i;
        i--;
    }

    return res;
}

int main()
{
    int64_t N;
    cin >> N;
    map<string, int64_t>d;
    for (int64_t i=0; i<N; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (d.count(s) > 0) {
            d[s] = d[s] + 1;
        } else {
            d[s] = 1;
        }
    }

    int64_t sum_count = 0;
    for (auto c : d) {
        if (c.second > 2) {
            int64_t i = c.second;
            while (i > 1) {
                sum_count += i - 1;
                i--;
            }
        } else if (c.second == 2) {
            sum_count += 1;
        }
    }

    cout << sum_count << endl;
    return 0;
}