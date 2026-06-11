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
    int N, M, num = 0;
    cin >> N >> M;
    vector <int> cs(N + 1, -1);
    bool bi=false;
    rep(i, M){
        int c, s;
        cin >> c >> s;
        if ((N != 1 && c == 1 && s == 0) || (cs[c] != s && cs[c] != -1)){
            bi = true;
        }
        cs[c] = s;
    }
    if (bi) {
        cout << -1 << endl;
        return 0;
    }
    repi(i, 1, N+1) {
        if (cs[i] == -1) continue;
        num += pow(10, N - i) * cs[i];
    }
    if (M == 0){
        num = 0;
    }
    if (num < pow(10, N - 1) && N > 1){
        num += pow(10, N - 1);
    }
    cout << num << endl;
    return 0;
}
