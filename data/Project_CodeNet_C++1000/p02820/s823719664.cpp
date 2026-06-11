// 素因数分解

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

    vector<vector<int>> f;
    vector<vector<ll>> dp;
    vector<int> t(3);

    ll dsp(int k,int kk, int p){
        if(kk==f[k].size()) return 0;
        if(p>=0 && dp[kk][p]!=-1){
            return dp[kk][p];
        }
        ll ret=0;
        rep(i,3){
            if(i==p) continue;
            ll ten=0;
            if(f[k][kk]==i) ten=t[i];
            ten+=dsp(k,kk+1,i);
            ret=max(ret,ten);
        }
        if(p>=0) dp[kk][p]=ret;
//        cout<<k<<" "<<kk<<" "<<p<<"  "<<ret<<endl;
        return ret;
    }

int main(){
    int N,K;
    cin>>N>>K;
    // R,S,P;
    rep(i,3)cin>>t[i];
    string s;
    cin>>s;
    int n=s.size();
    f.resize(K);
    rep(i,n){
        int k=i%K;
        if(s[i]=='s') f[k].push_back(0);
        else if(s[i]=='p') f[k].push_back(1);
        else f[k].push_back(2);
    }
    ll ans=0;
    rep(i,K){
        int n=f[i].size();
        dp.resize(n+1, vector<ll>(3));
        rep(j,n+1)rep(k,3) dp[j][k]=-1;
        ans+=dsp(i, 0, -1);
    }
    cout<<ans<<endl;
    return 0;
}