#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n,r;cin >>n>>r;
    ll ans;
    ans=n>10?r:r+100*(10-n);
    cout <<ans <<endl;
    return 0;
}

