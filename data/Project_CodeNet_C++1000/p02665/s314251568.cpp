#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N+1), acc(N+1);
    rep(i, 0, N+1){
        cin >> A[i];
        if(i == 0) acc[i] = A[i];
        else acc[i] = acc[i-1] + A[i];
    }
    ll ans = 0, par = 0;
    rep(i, 0, N+1){
        ll upper;
        if(i == 0) upper = min(1LL, acc[N]);
        else upper = min(2 * par, acc[N] - acc[i-1]);
        if(upper < A[i]){
            cout << -1 << endl;
            return 0;
        }
        ans += upper;
        par = upper - A[i];
    }
    cout << ans << endl;
    return 0;
}