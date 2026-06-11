#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;



int main() {
    int N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N)cin>>A.at(i);
    ll sum=0,ns=0;
    ll f1,f2;
    rep(i,N){
        sum+=A.at(i);
    }
    rep(i,N){
        ns+=A.at(i);
        if(ns>sum/2){
            f2=ns;
            f1=ns-A.at(i);
            break;
        }
    }
    f2=abs(sum-2*f2);
    f1=abs(sum-2*f1);
    cout<<min(f1,f2)<<endl;
}