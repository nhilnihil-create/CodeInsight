#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=998244353;

void Impsble(){
    cout<<0<<endl;
    exit(0);
}

int64_t ModPow(int64_t a, int64_t b){
    int64_t v=1;
    rep(i,0,b){
        v*=a;
        v%=MOD;
    }
    return v;
}

int main(){
    int N; cin>>N;
    vector<int> D(N);
    rep(n,0,N) cin>>D.at(n);

    if(D.front()!=0) Impsble();

    map<int,int> mp;
    rep(n,0,N) mp[D.at(n)]++;

    if(mp[0]!=1) Impsble();

    int64_t ans=1;
    for(auto itr=mp.begin();itr!=prev(mp.end()); itr++){
        if(itr->first+1!=next(itr)->first) Impsble();
        
        ans*=ModPow(itr->second,next(itr)->second);
        ans%=MOD;
    }

    cout<<ans<<endl;
}