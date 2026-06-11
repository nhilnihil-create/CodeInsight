#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
int MOD=1000000007;
int inf=1e9+7;
signed main(){
    int n,k;cin>>n>>k;
    vector<pair<int,int>> res;
    if(k>(n-1)*(n-2)/2){
        cout<<-1<<endl;
        return 0;
    }
    int m=0;
    rep1(i,n){
        for(int j=i+1;j<=n;++j){
            res.push_back({i,j});
            ++m;
        }
    }
    int cur=n-1;
    while(k>0){
        --k;
        res[cur].first=inf;
        res[cur].second=inf;
        --m;++cur;
    }
    cout<<m<<"\n";
    for(auto& val:res){
        if(val.first==inf){
            continue;
        }
        cout<<val.first<<" "<<val.second<<"\n";
    }
    return 0;
}