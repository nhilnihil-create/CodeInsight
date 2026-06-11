#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;

vector<ll> fact;

ll m_pow(ll p, ll n){
    if(n==0) return 1;
    else if(n%2){
        ll now = m_pow(p,(n-1)/2);
        return (now*now%MOD)*p%MOD;
    }
    else{
        ll now = m_pow(p,n/2);
        return now*now%MOD;
    }
}

ll m_comb(ll n, ll k){
    fact.resize(n+1);
    fact[0] = 1;
    rep(i,n) fact[i+1] = fact[i]*(i+1)%MOD;
    ll ans;
    ans = (fact[n]*m_pow(fact[k],MOD-2)%MOD)*m_pow(fact[n-k],MOD-2)%MOD;
    return ans;
}

int main(){
    int x,y;
    cin >> x >> y;
    if( (2*x-y)%3!=0 ||  (2*y-x)%3!=0 || (2*y-x)<0 || (2*x-y)<0 ) {
        cout << 0 << endl;
        return 0;
    }

    int l = (2*x-y)/3, k = (2*y-x)/3;
    //calc n+kCk
    cout << m_comb(k+l,k) << endl;
    return 0;
}