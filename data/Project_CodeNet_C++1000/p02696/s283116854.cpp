#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    long long A, B, N;
    cin >> A >> B >> N;
    long long ans1, ans2;
    long double xb1 = (N - (N%B) - 1)/(double)B;
    if (xb1 < 0) xb1 = 0;
    long double xb2 = N/(double)B;
    ans1 = floor(A*(xb1 - floor(xb1)));
    ans2 = floor(A*(xb2 - floor(xb2)));
    cout << max(ans1, ans2) << endl;
}
