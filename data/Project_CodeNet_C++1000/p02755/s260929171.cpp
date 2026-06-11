#include <bits/stdc++.h>
#define rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = (int)(a) ; i < (int)(b) ; i++)


#define SZ(x) ((int)(x).size())


typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
struct Vec{
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

template<class T>
T min(T a, T b)
{
    if (a < b) return a;
    return b;
}

template<class T>
T max(T a, T b)
{
    if (a > b) return a;
    return b;
}

using namespace std;

int main()
{
    int A, B;
    cin >> A >>B;
    double t = 25 * (double)A / 2;
    double f = 25 * (double)(A+1) / 2;
    repi(i, 10*B, 10*(B+1)){
        if (i >= t && i < f){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
