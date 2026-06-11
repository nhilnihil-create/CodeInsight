#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,P>
using namespace std;

vector<P> primes(ll a){
    vector<P> res;
    for(int i=2; i<=sqrt(a)+1; i++){
        if(a%i==0){
            res.push_back(P(i,1));
            a/=i;
            while(a%i==0){
                res.back().second++;
                a/=i;
            }
        }
    }
    if(a!=1) res.push_back(P(a,1));
    return res;
}

vector<ll> divisor(ll a){
    vector<ll> res;
    for(int i=2; i<=sqrt(a); i++){
        if(a%i==0){
            res.push_back(i);
            if(i!=a/i) res.push_back(a/i);
        }
    }
    res.push_back(a);
    // sort(all(a));
    return res;
}

int main(){
    ll n; cin >> n;
    vector<ll> dv;
    dv=divisor(n);
    //rep(i,dv.size()) cout << dv[i] << endl;
    ll ans=0;

    rep(i,dv.size()){
        ll tmp=n;
        while(tmp%dv[i]==0) tmp/=dv[i];
        if(tmp%dv[i]==1) ans++;
    }
    vector<P> ps;
    ps=primes(n-1);
    ll tmp=1;
    rep(i,ps.size()) tmp*=ps[i].second+1;
    ans+=tmp-1;
    cout << ans << endl;
return 0;
}
