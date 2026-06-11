#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t A, B;
    cin >> A >> B;
    if (A > 9 || B > 9 || A < 1 || B < 1) {
        cout << -1 << endl;
    } else {
        cout << A * B << endl;
    }
    return 0;
}