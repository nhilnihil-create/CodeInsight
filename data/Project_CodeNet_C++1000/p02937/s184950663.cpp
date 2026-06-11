#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool NG(string s, string t){
    map<char,int>mp1,mp2;
    rep(i,s.size())mp1[s[i]]++;
    rep(i,t.size())mp2[t[i]]++;
    for(auto&p:mp2){
        if(mp1[p.first]==0)return true;
    }
    return false;
}

int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    if(NG(s,t)){cout<<-1<<endl; return 0;}
    s+=s;
    vector<vector<int>>alp(26);
    ll ans=0;
    rep(i,s.size()){
        alp[s[i]-'a'].push_back(i);
    }
    int now=-1;
    rep(i,t.size()){
        int c=t[i]-'a';
        int x=upper_bound(alp[c].begin(),alp[c].end(),now)-alp[c].begin();
        ans+=alp[c][x]-now;
        now=alp[c][x];
        now%=n;
    }
    cout<<ans<<endl;
}