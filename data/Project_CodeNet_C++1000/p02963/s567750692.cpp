#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    long long S;
    cin >> S;
    
    long long X1, X2, X3, Y1, Y2, Y3;
    X1 = 0;
    Y1 = 0;
    X2 = 1e9;
    Y3 = (S - 1) / X2 + 1;
    X3 = 1;
    Y2 = X2 * Y3 - S;
    printf("%lld %lld %lld %lld %lld %lld\n", X1, Y1, X2, Y2, X3, Y3);
}