#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    string S; cin>>S;

    vector<vector<int64_t>> Dp(2,vector<int64_t>(2019,0));
    int64_t ans=0;
    rep(i,0,S.size()){
        int n=S.at(i)-'0';
        rep(j,0,2019) Dp.at(i&1).at(j)=0;
        rep(j,0,2019) Dp.at(i&1).at((j*10+n)%2019)+=Dp.at(!(i&1)).at(j);
        Dp.at(i&1).at(n)++;
        ans+=Dp.at(i&1).at(0);
    }

    cout<<ans<<endl;
}