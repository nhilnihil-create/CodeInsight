#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    int N; cin >> N;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];
    ll x2 = 0;
    rep(i,N){
        if (i%2==0) x2 += A[i];
        else x2 -= A[i];
    }

    vector<int> ans(N);
    ans[0] = x2/2;
    rep(i,N-1){
        ans[i+1] = A[i]-ans[i];
    }
    rep(i,N) ans[i] *= 2;
    rep(i,N) printf("%d%c", ans[i], i==N-1?'\n':' ');


}