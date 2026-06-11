#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
vector<int64_t> prime_factorize(int64_t N) {
    vector<int64_t> res;
    for (int64_t a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        int64_t b = N / a;
        res.emplace_back(a);
        res.emplace_back(b);
    }

    // 最後に残った数について
    if (N != 1) res.emplace_back(N);
    return res;
}

int main()
{
    int64_t N;
    cin >> N;
    int64_t min_ = INT64_MAX;
    vector<int64_t> vec = prime_factorize(N);
    for (int64_t i=0; i<vec.size(); i++) {
            int64_t n = vec[i];
            int64_t b = N / n;
            int64_t score = (n - 1) + (b - 1);
            if (min_ > score) {
                min_ = score;
            }
    }

    cout << min_ << endl;
    return 0;
}