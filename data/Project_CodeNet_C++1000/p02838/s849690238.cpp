#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> K(60, 0);

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> tmp;
        //cout << bitset<60>(tmp) << endl;
        ll k=0;
        while(tmp>=1) {
            K[k] += tmp%2;
            k++;
            tmp /= 2;
        }
    }
    ll d=1;
    for(int i=0;i<60;i++) {
        ans += (d*K[i]%MOD)*(N-K[i])%MOD;
        ans %=MOD;
        //cout << K[i] << " " << ans << endl;
        d*=2;
        d%=MOD;
    }
    cout << ans << endl;
    return 0;
}