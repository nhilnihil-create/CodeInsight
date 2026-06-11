#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    if(abs(A-B)%2==0){
        cout << abs(A-B)/2 << endl;
    }else{
        // 片方が端まで行って1回その場に留まる
        ll l = A-1;
        ll r = N-B;
        if(l<=r){
            // 左端でAが留まる.Bは左端に向かう
            ll ans = l+1; //左端に来て1回留まった状態
            ans += (B-l-2)/2;
            cout << ans << endl;
        }else{
            ll ans = r+1;
            ans += (N-(A+r+1))/2;
            cout << ans << endl;
        }
    }
    return 0;
}