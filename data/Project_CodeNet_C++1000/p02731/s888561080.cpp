#include <bits/stdc++.h>
#define rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a) ; i < (int)(b) ; i++)


#define SZ(x) ((int)(x).size())


typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
struct Vector{
    double x, y;
};

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
using namespace std;

int main()
{
    double L;
    cin >> L;
    double k = L*L*L / 27;
    printf("%.15f\n", k);
    return 0;
}
