#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

const ll MOD = 1000000007;

int main() {
    int N; ll K; cin >> N >> K;
    veci A(N);
    REP(i,N) cin >> A[i];
    ll ans = 0;
    REP(i,N) {
        int r = 0;
        int l = 0;
        for(int j = i+1; j < N; j++) if(A[i] > A[j]) r++;
        for(int j = i-1; j >= 0; j--) if(A[j] < A[i]) l++;
        ll total = K*(K+1)/2;
        total %= MOD;
        ans += r * total;
        ans %= MOD;
        total = K*(K-1)/2;
        total %= MOD;
        ans += l * total;
        ans %= MOD;
    }
    for(int i = N-1; i >= 0; --i) {

    }
    cout << ans << endl;
}

