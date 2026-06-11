#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int64_t gcd(int64_t a, int64_t b) {
    if (b > a) {
        int64_t c = a;
        a = b;
        b = c;
    }

    if (a % b == 0) {
        return b;
    }

    int64_t c = a % b;
    return gcd(b, c);
}

int main()
{
    int64_t A, B, C, D;
    cin >> A >> B >> C >> D;
    int64_t c_ = (B / C) - (A / C);
    if (A % C == 0) c_ += 1;
    int64_t d_ = (B / D) - (A / D);
    if (A % D == 0) d_ += 1;
    int64_t E = C * D / gcd(C, D);
    int64_t e_ = (B / E) - (A / E);
    if (A % E == 0) e_ += 1;
    cout << (B - A + 1) - (c_ + d_) + e_ << endl;
    return 0;
}