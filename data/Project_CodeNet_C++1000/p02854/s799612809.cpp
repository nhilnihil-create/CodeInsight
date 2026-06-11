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
    int64_t sum = 0;
    for (int64_t i=0; i<N; i++) {
        cin >> vec.at(i);
        sum += vec[i];
    }

    int64_t sum_price = 0;
    int64_t min_sa = INT64_MAX;
    int64_t now = 0;
    for (int64_t i=0; i<N; i++) {
        now += vec[i];
        int64_t sa = abs((sum - now) - now);
        if (min_sa >  sa) {
            min_sa = sa;
        }
    }

    cout << min_sa << endl;
    return 0;
}