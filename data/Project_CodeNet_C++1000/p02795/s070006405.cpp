#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
     ll h,w,n;cin >>h>>w>>n;
     ll mx=max(h,w);
    ll ans=(n-1)/mx+1;
    cout<<ans <<endl;
    return 0;
}
