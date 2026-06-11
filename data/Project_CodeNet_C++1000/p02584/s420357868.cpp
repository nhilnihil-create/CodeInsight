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
    ll X,K,D;
    cin >> X >> K >> D;
    X = abs(X);

    if(X / D >= K){
        cout << X-K*D << endl;
        return 0;
    }

    K -= X / D;
    X = X % D;

    if(K % 2 == 0){
        cout << X << endl;
    }else{
        cout << D - X << endl;
    }
    return 0;


}