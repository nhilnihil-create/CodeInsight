// 素因数分解

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

    vector<vector<int>> f;
    vector<vector<ll>> dp;
    vector<int> t(3);

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
        int p=1;
        ans+=t[f[i][0]];
        for(int j=1;j<n;j++){
            if(f[i][j-1]==f[i][j]){
                if(p==0){
                    ans+=t[f[i][j]];
                    p=1;
                }
                else p=0;
            }
            else{
                p=1;
                ans+=t[f[i][j]];
            }
        }
        
    }
    cout<<ans<<endl;
    return 0;
}