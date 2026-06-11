#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    cin >> N;
    veci A(N);
    REP(i,N) cin >> A[i];
    veci ans(N);
    for(int i = N-1; i >= 0; --i) {
        int total = 0;
        for(int j = 2; j <= N/(i+1); j++) total += ans[(i+1)*j-1];
        if(total%2 == A[i]) ans[i] = 0;
        else ans[i] = 1;
    }
    veci b;
    for(int i = 0; i < N; i++) {
        if(ans[i]) b.push_back(i+1);
    }
    cout << b.size() << endl;
    if(b.size() > 0) {
    for(int i: b) cout << i << " ";
    cout << endl;
    }
}
