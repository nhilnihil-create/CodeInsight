#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, k; cin >> n >> k;
    vector<ll> A(n); rep(i, n) cin >> A[i];

    ll ng = 0, ok = INF;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        //k回以内の操作でいずれの丸太も長さをmid以下にできるか
        int cnt = 0;
        rep(i, n){
            double tmp = A[i] / (double)mid;
            int num = ceil(tmp) - 1;
            cnt += num;
        }
        if(cnt <= k)ok = mid;
        else ng = mid;
    }
    cout << ok << ln;
}
    
