#include<bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

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

int main() {
    double L;
    cin >> L;
    double ans = (1.0/27.0)*pow(L, 3.0);
    printf("%lf",ans);
}