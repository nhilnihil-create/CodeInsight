#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

void Dfs(vector<string> &A,string S,int idx,int k, int N){
    if(idx>=N){
        A.push_back(S);
        return;
    }

    rep(i,0,k){
        S.at(idx)='a'+i;
        Dfs(A,S,idx+1,max(k,i+2),N);
    }
}

int main(){
    int N; cin>>N;

    vector<string> ans;
    string _ans;
    rep(n,0,N) _ans+='a';

    Dfs(ans,_ans,1,2,N);

    for(auto a:ans) cout<<a<<endl;
}