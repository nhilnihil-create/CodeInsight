#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    ll n; cin>>n;
    ll ans=0;
    rep(i,n){
        if((i+1)%3==0){
            continue;
        }
        if((i+1)%5==0){
            continue;
        }
        ans+=i+1;
    }
    cout<<ans<<endl;
}