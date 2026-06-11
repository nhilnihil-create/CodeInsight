#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

vector<ll> Prime_fac(ll n){
    vector<ll> res;
    for(ll i=2; i*i<=n; i++){
        ll tmp=0;
        while(n%i == 0){
            tmp++;
            n/=i;
        }
        if(tmp) res.push_back(tmp);
    }
    if(n != 1) res.push_back(1);
    return res;
}

int main(){
    ll N; cin >> N;
    vector<ll> val=Prime_fac(N);
    ll res=0;
    for(int i=0; i<(int)val.size(); i++){
        int j=0;
        while(val[i] > j){
            res++;
            j++;
            val[i]-=j;
        }
    }
    cout << res << endl;
    return 0;
}