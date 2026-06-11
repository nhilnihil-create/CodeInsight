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

ll my_pow(ll a, ll n){
    ll res=1;
    while(n > 0){
        if(n & 1) res=res*a;
        a=a*a;
        n>>=1;
    }
    return res;
}

int main(){
    ll H; cin >> H;
    int cnt=0;
    ll res=0;
    while(H > 0){
        res+=my_pow(2LL, (ll)cnt);
        H/=2;
        cnt++;
    }
    cout << res << endl;
    return 0;
}