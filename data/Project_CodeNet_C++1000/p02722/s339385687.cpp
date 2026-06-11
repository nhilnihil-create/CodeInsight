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
    if(N==2){
        cout<<1<<endl;
        return 0;
    }
    set<ll> F;//factor
    for(ll i = 2; i <= sqrt(N); i++){
        if(N%i==0){
            F.insert(i);
            F.insert(N/i);
        }
    }

    for(ll i = 2; i <= sqrt(N-1); i++){
        if((N-1)%i==0){
            F.insert(i);
            F.insert((N-1)/i);
        }
    }

    ll res = 2;
    for(auto i: F){
        ll n = N;
        while(n>=i){
            if(n%i==0)n = n/i;
            else{
                if(n%i==1)n = 1;
                else break;
            }
        }
        if(n==1)res++;
    }
    cout<<res<<endl;
}
