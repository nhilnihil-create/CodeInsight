#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n,a,b;cin >>n>>a>>b;
    ll ans=0;
    if(a%2==b%2){
        ans=(b-a)/2;
    }
    else {
        ans+=min(n-b+1,a);
        ans+=(b-a)/2;
    }
    cout <<ans <<endl;
    return 0;
}
