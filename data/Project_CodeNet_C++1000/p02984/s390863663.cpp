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
    vecl A(N);
    REP(i,N) cin >> A[i];
    vecl ans(N);
    REP(i,N) {
        if(i%2 == 0) ans[0] += A[i];
        else ans[0] -= A[i];
    }
    REP(i,N-1) {
        ans[i+1] = 2*(A[i] - ans[i]/2);
    }
    REP(i,N) cout << ans[i] << " ";
    cout << endl;
}
