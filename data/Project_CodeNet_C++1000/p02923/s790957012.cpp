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
    vector<int64_t>vec(N);
    for (int64_t i=0; i<N; i++) {
        cin >> vec.at(i);
    }

    int64_t max_ = 0;
    int64_t n = vec[0];
    int64_t now_count = 0;
    for (int64_t i=1; i<N; i++) {
        if (n >= vec[i]) {
            now_count += 1;
            if (now_count > max_) {
                max_ = now_count;
            }
        } else {
            now_count = 0;
        }
        n = vec[i];
    }

    cout << max_ << endl;
    return 0;
}