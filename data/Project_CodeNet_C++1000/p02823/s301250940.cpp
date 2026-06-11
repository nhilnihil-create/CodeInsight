#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N, A, B;
    cin >> N >> A >> B;
    int64_t sa = abs(A-B);
    if (A == B) {
        cout << 0 << endl;
    } else if (sa % 2 == 0) {
        cout << sa / 2 << endl;
    } else {
        int64_t min_ = min(A, B);
        int64_t max_ = max(A, B);
        if (sa == 1) {
            int64_t haiboku_idoukyori = N - min_;
            cout << min(haiboku_idoukyori, max_ - 1) << endl;
        } else {
        int64_t hikukazu = min_ - 1;
        int64_t tasukazu = N - max_;
        int64_t to_one_idoukyori = min_ + (max_ - hikukazu - 1) / 2;
        int64_t to_max_idoukyori = tasukazu + ((N - (min_ + tasukazu) - 1) / 2) + 1;
        cout << min(to_one_idoukyori, to_max_idoukyori) << endl;
        }
    }
    return 0;
}