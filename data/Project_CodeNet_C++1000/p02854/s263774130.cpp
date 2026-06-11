//url:
//problem name: Brick Break

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    cin >> N;
    vecl A(N);
    REP(i,N) cin >> A[i];
    vecl S(N+1);
    REP(i,N) S[i+1] = S[i] + A[i];
    ll ans = S[N]+1;
    for(int i = 0; i <= N; ++i) {
        chmin(ans,(ll)abs(S[i]-(S[N]-S[i])));
    }
    cout << ans << endl;
}
