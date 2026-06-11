#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    vector<ll> A(N+1);
    ll total = 0;
    rep(i, N){
        cin >> A[i+1];
        total += A[i+1];
    }

    vector<ll> ans(N+1);
    ll s = 0;
    for (int i = 2; i <= N-1; i+=2){
        s += A[i];
    }

    ans[1] = total - 2*s;

    for (int i = 2; i <= N; i++){
        ans[i] = A[i-1]*2 - ans[i-1];
    }

    rep(i, N){
        cout << ans[i+1];
        if (i != N-1){
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}