#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    ll N; cin>>N;
    ll res = 0;
    for(ll i = 1; i <= N; i++){
        ll tmp1 = N/i;
        res += (1+tmp1)*tmp1*i/2.0;
        
    }
    cout<<res<<endl;
}