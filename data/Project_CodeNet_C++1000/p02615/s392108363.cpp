#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60; //intじゃ扱えないことに注意！
using P = pair<int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++) //範囲外参照とループの初期化に注意！

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    sort(A.rbegin(),A.rend());
    ll ans = 0;
    ll t = N-1;
    int i = 0;
    while(t > 0){
        if(i == 0){
            ans += A[i];
            t--;
            i++;
            continue;
        }
        rep(j,2){
            ans += A[i];
            t--;
            if(t <= 0) break;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}