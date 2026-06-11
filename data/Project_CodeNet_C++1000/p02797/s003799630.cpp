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
    int N, K; cin >> N >> K;
    ll S; cin >> S;
    vecl ans(N);
    ll res;
    if(S == 1e9) res = 1;
    else res = S+1;
    REP(i,K) ans[i] = S;
    for(int i = K; i < N; i++) {
        ans[i] = res;
    }
    for(auto x: ans) cout << x << " ";
    cout << endl;
}