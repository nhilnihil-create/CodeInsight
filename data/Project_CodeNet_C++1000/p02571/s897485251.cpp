#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define debug(output) cout<<#output<<"= "<<output<<endl
using lint=long long;
int MOD=1000000007;
int inf=1e9+7;
int calc(string const& sub,string const& t){
    int n=sub.length();
    int res=0;
    rep(i,n){
        if(sub[i]!=t[i])++res;
    }
    return res;
}
signed main(){
    string s,t;cin>>s;
    cin>>t;
    int res=inf;
    int sLen=s.length();
    int tLen=t.length();
    rep(i,sLen-tLen+1){
        string sub=s.substr(i,tLen);
        res=min(res,calc(sub,t));
    }
    cout<<res<<"\n";
    return 0;
}