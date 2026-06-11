
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    if(n<=k){
        cout << 0 << endl;
        return 0;
    }

    //体力が多いモンスター上位k体は必殺技で倒す
    sort(all(h));
    rep(i,k){
        h.pop_back();
    }
    ll ans=0;
    for(int i=0; i<n-k; i++){
        ans += h.at(i);
    }
    cout << ans << endl;
    return 0;

}   