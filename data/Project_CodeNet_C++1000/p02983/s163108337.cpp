#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

//---main---------------------------------------------
int main(){
    //main
    ll L,R;
    cin >> L >> R;
    ll ans = 2020;
    ll imax;
    imax = min(L+4038,R);

    for(ll i = L; i<=imax; ++i){
        for(ll j = i+1; j<=imax; ++j) chmin(ans, (i*j)%2019 );
    }

    cout << ans << endl;

    return 0;
}