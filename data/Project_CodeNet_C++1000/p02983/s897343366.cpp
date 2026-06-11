#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int64_t amaririyou(int64_t L, int64_t R) {
    int64_t mod_l = L % 2019;
    int64_t mod_r = R % 2019;

    int64_t min_ = INT64_MAX;
    if (R - L >= 2019 || mod_r <= mod_l) {
        return 0;
    } else {
        for (int i=mod_l; i<mod_r; i++) {
            for (int j=i+1; j<=mod_r; j++) {
                int64_t num = i * j % 2019;
                if (min_ > num) {
                    min_ = num;
                }

                if (min_ == 0) {
                    break;
                }
            }

            if (min_ == 0) {
                break;
            }
        }
        return min_;
    }
}

int64_t gutyokukai(int64_t L, int64_t R) {
    int64_t min_ = INT64_MAX;
    for (int64_t i=L; i<R; i++) {
        int64_t l = i % 2019;
        for (int64_t j=i+1; j<=R; j++) {
            int64_t r = j % 2019;
            int64_t num = l * r % 2019;
            if (min_ > num) {
                min_ = num;
            }

            if (min_ == 0) {
                cout << i << endl;
                cout << j << endl;
                return min_;
            }
        }
    }

    return min_;
}

int main()
{
    int64_t L, R;
    cin >> L >> R;
    cout << amaririyou(L, R) << endl;

    return 0;
}