#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N, A, B;
    ll temp;
    cin >> N >> A >> B;
    temp = B - A;
    if(temp % 2) {
        temp = min(A - 1, N - B) + 1 + (B - A - 1) / 2;
    } else {
        temp /= 2;
    }
    cout << temp << endl;
    return 0;
}
