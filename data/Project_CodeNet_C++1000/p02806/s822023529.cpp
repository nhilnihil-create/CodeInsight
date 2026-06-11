#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n;
    cin>>n;
    vector<pair<string,int>>p(n);
    rep(i,n){
        string s; int t;
        cin>>s>>t;
        p[i]=make_pair(s,t);
    }
    string ss; cin>>ss;
    int x;
    rep(i,n){
        if(ss==p[i].first)x=i;
    }
    int ans=0;
    for(int i=x+1; i<n; ++i){
        ans+=p[i].second;
    }
    cout<<ans<<endl;
}