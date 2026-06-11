#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)
const ll mod = 998244353;

ll N;
vector<ll> D;

int main(){
    cin >> N;
    map<int,int> m;
    D.assign(N,0);
    rep(i,0,N){
        cin >> D[i];
        m[D[i]]++;
    }

    if(D[0]!=0 || m[0]>1){
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    ll ans = 1;
    ll pre = 1;
    ll pre_d = -1;
    for(auto &e : m){
        cnt++;
        if(pre_d+1 != e.first){
            cout << 0 << endl;
            return 0;
        }
        if(cnt<=2){
            pre_d = e.first;
            pre = e.second;
            continue;
        }

        rep(i,0,e.second){
            ans *= pre;
            ans %= mod;
        }
        pre_d = e.first;
        pre = e.second;
    }
    cout << ans << endl;
}