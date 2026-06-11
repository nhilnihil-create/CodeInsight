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
    int M;
    cin>>M;
    vector<pair<int,ll>> dc(M);
    rep(i,M)cin>>dc.at(i).first>>dc.at(i).second;
    ll keta=0;
    rep(i,M){
        keta+=dc.at(i).second;
    }
    ll sum=0;
    rep(i,M){
        sum+=dc.at(i).first*dc.at(i).second;
    }
    if(sum%9==0){sum-=9;}
    sum/=9;
    cout<<sum+keta-1<<endl;
}