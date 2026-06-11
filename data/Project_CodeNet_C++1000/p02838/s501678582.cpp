#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N; cin>>N;
    vector<ll> A(N); rep(i,N)cin>>A.at(i);

    ll res = 0;
    ll two = 1;
    for(int i = 0; i < 60; i++){
        ll zero = 0, one = 0;
        for(ll n = 0; n < N; n++){
            if(A.at(n)&(1LL<<i))one++;
            else zero++;
        }
        //res += (zero*one*two)%MOD;
        ll add = (zero*one)%MOD*two%MOD;
        res = (res+add) %MOD;
        two = (two*2)%MOD;
    }
    cout<<res<<endl;
}
