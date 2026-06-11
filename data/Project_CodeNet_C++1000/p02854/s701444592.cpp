#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    uint64_t sum=0;
    vector<uint64_t> A(N);
    rep(n,0,N){cin>>A.at(n); sum+=A.at(n);}

    vector<vector<int64_t>> sumH(2,vector<int64_t>(N+1,0));
    sumH.at(1).at(0)=sum;

    rep(n,1,N+1){
        sumH.at(0).at(n)=sumH.at(0).at(n-1)+A.at(n-1);
        sumH.at(1).at(n)=sumH.at(1).at(n-1)-A.at(n-1);
    }

    int64_t minD=INT64_MAX;
    rep(n,1,N+1){
        minD=min(minD,abs(sumH.at(0).at(n)-sumH.at(1).at(n)));
    }

    cout<<minD<<endl;
}