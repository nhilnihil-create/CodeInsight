#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int> A(N);
    rep(n,0,N) cin>>A.at(n);

    map<int,int> mp;
    for(auto a:A) mp[a]++;

    string ans="No";
    if(mp.size()==1){
        if(mp.count(0)) ans="Yes";
    }else if(mp.size()==2){
        if(N%3==0){
            bool correct=true;
            for(auto m:mp){
                if(m.first==0){if(m.second!=N/3) correct=false;}
                else{if(m.second!=2*N/3) correct=false;}
            }
            if(correct) ans="Yes";
        }
    }else{
        if(N%3==0){
            bool correct=true;
            vector<int> v;
            for(auto m:mp){
                v.push_back(m.first);
                if(m.second!=N/3) correct=false;
            }
            if((v.at(0)^v.at(1))!=v.at(2) || (v.at(1)^v.at(2))!=v.at(0) || (v.at(2)^v.at(0))!=v.at(1)) correct=false;
            if(correct) ans="Yes";
        }
    }

    cout<<ans<<endl;
}