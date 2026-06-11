#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    LL N,K;cin >> N >> K;
    vector<LL> A(N);
    vector<LL> F(N);
    rep(i,N)cin >> A[i];
    rep(i,N)cin >> F[i];

    sort(all(A));
    sort(rall(F));

    LL ub = 1e18;
    LL lb = -1;
    while(ub-lb > 1){
        LL mid = (ub+lb)/2;
        LL tmp = 0;
        rep(i,N){
            LL a = mid/F[i];
            LL sa = A[i] - a;
            if(sa > 0){
                tmp += sa;
            }
        }
        if(tmp <= K){
            ub = mid;
        }
        else{
            lb = mid;
        }
    }

    cout << ub << endl;

}