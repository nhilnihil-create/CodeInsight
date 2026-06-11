#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
int MOD=1000000007;
int inf=1e9+7;
signed main(){
    int n;cin>>n;
    vector<int> p(n+1,0);
    vector<int> memo(n+1,0);
    rep1(i,n){
        int buf;cin>>buf;
        p[i]=buf;
        memo[buf]=i;
    }
    int res=0;
    map<int,int> array;
    array[0]=0;
    array[n+1]=n+1;
    for(int i=n;i>0;--i){
        array[memo[i]]=i;
        auto it=array.find(memo[i]);
        auto b=it;--b;
        auto f=it;++f;
        int buf=0;
        int sup=min(f->first,n+1);
        if(b->second!=0){
            auto bb=b;--bb;
            buf+=(b->first-bb->first)*(f->first-it->first)*it->second;
        }
        if(f->second!=n+1){
            auto ff=f;++ff;
            buf+=(ff->first-f->first)*(it->first-b->first)*it->second;
        }
        res+=buf;
    }
    cout<<res<<"\n";
    return 0;
}