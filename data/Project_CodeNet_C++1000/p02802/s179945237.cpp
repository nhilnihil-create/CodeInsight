#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int INF = 1001001001;

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
    int n, m;
    cin >> n >> m;
    vector<bool> ac(n, false);
    vector<int> wa(n);
    rep(i,m) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (s == "AC") ac[p] = true;
        if (s == "WA") {
            if (!ac[p]) wa[p]++;
        } 
    }
    int ansac = 0, answa = 0;
    rep(i,n) {
        if (ac[i]) ansac++;
    }
    rep(i,n) {
        if (ac[i]) answa += wa[i];
    }
    printf("%d %d\n", ansac, answa);
    return 0;
}
