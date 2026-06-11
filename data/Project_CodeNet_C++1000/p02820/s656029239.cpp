#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
char katerute(char dasite) {
    if (dasite == 'r') {
        return 'p';
    } else if (dasite == 's') {
        return 'r';
    } else {
        return 's';
    }
}
int main()
{
    int64_t N, K;
    cin >> N >> K;
    int64_t R, S, P;
    cin >> R >> S >> P;
    string T;
    cin >> T;
    int64_t sum_score = 0;
    vector<char>vec(N);
    for (int64_t i=0; i<N; i++) {
        char dasite = T[i];
        char katite = katerute(dasite);
        int64_t add_score = 0;
        if (katite == 'r') {
            add_score = R;
        } else if (katite == 'p') {
            add_score = P;
        } else {
            add_score = S;
        }

        if (i - K >= 0) {
            if (vec[i-K] == katite) {
                vec[i] = '-';
            } else {
                vec[i] = katite;
                sum_score += add_score;
            }
        } else {
            vec[i] = katite;
            sum_score += add_score;
        }
    }

    cout << sum_score << endl;
    return 0;
}