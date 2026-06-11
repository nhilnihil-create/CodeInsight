#include <bits/stdc++.h>
using namespace std;
#define SELECTER(_1, _2, _3, SELECT, ...) SELECT
#define REP1(i, n) for(int i=0; i<n; i++)
#define REP2(i, a, b) for(int i=a; i<b; i++)
#define REP(...) SELECTER(__VA_ARGS__, REP2, REP1,) (__VA_ARGS__)
#define MOD 1'000'000'007

template <class T> ostream& operator<<(ostream& os, const vector<T>& v){ os << "{"; for(size_t i=0; i<v.size(); i++) os << v[i] << (i+1==v.size() ? "" : ", "); os << "}"; return os; }
template <class T, class U> ostream& operator<<(ostream& os, const pair<T, U>& p){ return os << "{" << p.first << ", " << p.second << "}"; }

int main(){
    int M;
    cin >> M;
    vector<long long> d(M), c(M);
    REP(i, M) cin >> d[i] >> c[i];

    long long S = 0;
    long long D = 0;
    REP(i, M)
        D += c[i];
    REP(i, M)
        S += c[i] * d[i];

    long long ans = D-1+(S-1)/9;
    cout << ans << endl;
    return 0;
}
