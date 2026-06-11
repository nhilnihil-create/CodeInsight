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


    map<int64_t, int64_t>d;
    for (int64_t i=0; i<N; i++) {
        int64_t num = vec[i];
        if(d.count(num) > 0) {
            d[num] = d[num] + 1;
        } else {
            d[num] = 1;
        }
    }

    int64_t number_count = 0;
    int64_t count = 0;
    int64_t num = 0;
    bool is_first = true;
    bool is_can = true;
    for (auto c : d) {
        if (is_first) {
            num = c.first;
            count += 1;
            number_count = c.second;
            is_first = false;
        } else {
            num = num^c.first;
            count += 1;
            if (number_count != c.second) {
                is_can = false;
                break;
            }
        }
    }

    if (d[0] > 0 && count <= 2) {
        int64_t zero_count = 0;
        int64_t other_count = 0;
        for (auto c: d) {
            if (c.first == 0) {
                zero_count = c.second;
            } else {
                other_count = c.second;
            }
        }

        if (other_count == 0 || zero_count*2==other_count) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (is_can && num == 0 && count == 3) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}