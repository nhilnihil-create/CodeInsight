#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

vector<ll> prime_fac(ll n){
    vector<ll> res;
    for(ll i=2; i*i<=n; i++){
        bool ok=false;
        while(n%i == 0){
            n/=i;
            ok=true;
        }
        if(ok) res.push_back(i);
    }
    if(n != 1) res.push_back(n);
    return res;
}

int main(){
    ll A, B; cin >> A >> B;
    vector<bool> check(1001001, 0);
    vector<ll> fac;
    fac=prime_fac(A);
    ll res=0;
    for(auto &x : fac){
        if(B%x == 0) res++;
    }
    res++;
    cout << res << endl;
    return 0;   
}