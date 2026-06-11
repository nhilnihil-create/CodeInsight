#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,Q;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    rep(i,N){
        ll a;
        cin >> a;
        fw.add(i,a);
    }
    rep(i,Q){
        ll t,p,x;
        cin >> t >> p >> x;
        if (t == 0){
            fw.add(p,x);
        }
        if (t == 1){
            ll ans = fw.sum(p,x);
            cout << ans << endl;
        }
    }
}