#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
const long long INFLL = 1LL << 60;
const int INFINT = 1 << 30;
const long long MOD = 1e9 + 7;

bool isPrime(int n) {
    if(n < 2)
        return false;
    else if(n == 2)
        return true;
    else if(n % 2 == 0)
        return false;
    double sq = sqrt(n);
    for(int i = 3; i <= sq; i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int X;
    cin >> X;
    while(!isPrime(X)) {
        X++;
    }
    cout << X << endl;
}