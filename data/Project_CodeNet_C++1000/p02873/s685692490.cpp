#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;

    vector<int64_t> v(S.size()+1,0);
    rep(i,1,S.size()+1){    //i=1,2,3,...,S.size()
        char s=S.at(i-1);
        if(s=='<') v.at(i)=max(v.at(i),v.at(i-1)+1);
    }

    _rep(i,S.size()-1,0){   //i=S.size()-1,S.size()-2,...,2,1,0
        char s=S.at(i);
        if(s=='>') v.at(i)=max(v.at(i),v.at(i+1)+1);
    }

    int64_t ans=0;
    rep(i,0,v.size()) ans+=v.at(i);
    cout<<ans<<endl;
}