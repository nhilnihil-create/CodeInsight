#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n; ll k; cin >> n >> k;
    vector<int> A(n),F(n);
    ll ans = 0;
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> F[i];
    sort(ALL(A));
    sort(F.rbegin(),F.rend());
    ll ng = -1,ok = 1e18;
    while(ok-ng > 1){
        ll c = (ng+ok)/2;
        bool check = [&]{
            ll s = 0;
            rep(i,n){
                s += max(0ll,A[i]-c/F[i]);
            }
            return s <= k;
        }();
        if(check) ok = c; else ng = c;
    }
    cout << ok << endl;
}