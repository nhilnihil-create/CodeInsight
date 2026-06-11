#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    ll N,K; cin>>N>>K;
    vector<ll> A(N); rep(i,N)cin>>A.at(i);

    ll left = 0, right = 1e9;
    while(right-left>1){
        ll mid = left + (right-left)/2;
        ll cnt = 0;
        rep(i,N){
            cnt += (A.at(i)-1)/mid;
        }
        if(cnt<=K)right = mid;
        else left = mid;
    }
    cout<<right<<endl;
}