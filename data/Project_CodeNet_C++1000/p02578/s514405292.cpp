#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
const long long INF = 1LL << 60;
const int MOD = 1e9 + 7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


/* ACL */

//using namespace atcoder;



int main(){
    ll N;
    cin >> N;
    vector<ll>  A(N);
    rep(i,N){
        cin >> A.at(i);
    }

    ll cnt = 0;
    ll bef = A.at(0);
    rep(i,N-1){
        if( bef > A.at(i+1)){
            cnt += (bef - A.at(i+1));
            A.at(i+1) = bef;
        }
        bef = A.at(i+1);
    }
    cout << cnt << endl;
    return 0;

}