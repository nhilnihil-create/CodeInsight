#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

ll modpow(ll a, ll n, ll mod){
    ll res=1;
    while(n > 0){
        if(n & 1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    vi cnt(60);
    for(int i=0; i<N; i++){
        for(int j=0; j<60; j++){
            if(A[i]>>j & 1) cnt[j]++;
        }
    }
    ll res=0;
    for(ll i=0; i<60; i++){
        res=(res+cnt[i]%MOD*(N-cnt[i])%MOD*modpow(2LL, i, MOD)%MOD)%MOD;
    }
    cout << res << endl;
    return 0;
}