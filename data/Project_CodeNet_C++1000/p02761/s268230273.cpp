#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int N, M;
    cin >> N >> M;
    vector<bool>vec(1000, true);
    vector<pair<int, int>>pairs(M);
    for (int i=0; i<=999; i++) {
        if (i < 10) {
            if (N != 1) {
                vec[i] = false;
            }
        } else if (i < 100) {
            if (N != 2) {
                vec[i] = false;
            }
        } else {
            if (N != 3) {
                vec[i] = false;
            }
        }
    }
    for (int i=0; i<M; i++) {
        int s, c;
        cin >> s >> c;
        pairs[i] = make_pair(s, c);
    }

    int min_ = 0;
    int max_ = 0;
    if (N == 1) {
        max_ = 9;
    } else if (N == 2) {
        min_ = 10;
        max_ = 99;
    } else {
        min_ = 100;
        max_ = 999;
    }

    for (int i=0; i<M; i++) {
        int s = pairs[i].first;
        int c = pairs[i].second;
        for (int i=min_; i<=max_; i++) {
            if (N == 1) {
                int v = i % 10;
                if (v != c) {
                    vec[i] = false;
                }
            } else if (N == 2) {
                int v = 0;
                if (s == 1) {
                    v = (i / 10) % 10;
                } else {
                    v = i % 10;
                }

                if (v != c) {
                    vec[i] = false;
                }
            } else {
                int v = 0;
                if (s == 1) {
                    v = ((i / 10) / 10) % 10;
                } else if (s == 2) {
                    v = (i / 10) % 10;
                } else {
                    v = i % 10;
                }

                if (v != c) {
                    vec[i] = false;
                }
            }
        }
    }

    bool is_ok = false;
    for (int i=0; i<1000; i++) {
        if (vec[i]) {
            cout << i << endl;
            is_ok = true;
            break;
        }
    }

    if (!is_ok) {
        cout << "-1" << endl;
    }
    return 0;
}