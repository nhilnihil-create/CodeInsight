#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    string S;
    cin >> S;
    int64_t s_size = S.size();
    int64_t split_count = 0;
    int skip_count = 0;
    for (int i=0; i<s_size; i++) {
        if (skip_count > 0) {
            skip_count--;
        } else {
            if (i<s_size-2) {
                split_count += 1;
                if (S[i] == S[i+1]) {
                    split_count += 1;
                    skip_count += 2;
                }
            } else if (i<s_size-1) {
                split_count += 1;
                if (S[i] == S[i+1]) {
                skip_count += 1;
                }
            } else {
                split_count += 1;
            }
        }
    }

    cout << split_count << endl;
    return 0;
}