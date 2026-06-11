#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>

int main() {
    ll N; cin >> N;
    vl A(N);
    rep(i,N) cin >> A[i];

    bool ans = true;
    rep(i,N){
        if(A[i] % 2 == 0){
            if(A[i] % 3 != 0 && A[i] % 5 != 0){
                ans = false;
                break;
            }
        }
    }

    if(ans) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;
}