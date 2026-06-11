#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n + 1); ++i)
using namespace std;
using ll = long long;
const int INF = +100100100;
typedef pair<int,int> P;


vector<ll> enumdivisor(ll n){
    vector<ll> y;
    for(ll k =1 ; k*k<=n;++k){
        if(n%k!=0)continue;
        y.push_back(k);

        if(k*k!=n)y.push_back(n/k);
    }
    return y;
}


int main(){
    ll n;
    cin >> n;
    ll ans=0;
    for(ll x : enumdivisor(n)){
        if(x==1)continue;
        ll tmp = n;
        while(tmp%x==0)tmp/=x;
        tmp%=x;
        if(tmp==1)++ans;
    }
    ans+=enumdivisor(n-1).size()-1;
    cout << ans << endl;
    return 0;
}
