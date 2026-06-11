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
    ull N, A, B, comb, temp;
    cin >> N >> A >> B;
    comb = N / (A+B);
    if (N - comb* (A+B) > A) temp = A;
    else temp = N - comb * (A+B); 
    cout << comb * A + temp << endl;
    return 0;
}
