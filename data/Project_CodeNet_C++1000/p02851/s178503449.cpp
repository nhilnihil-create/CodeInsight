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
int MOD=1000000007;
signed main(){
    int n,k;cin>>n>>k;
    vector<int> a(n+1);
    rep1(i,n)cin>>a[i];
    vector<int> sum(n+1,0);
    rep1(i,n)sum[i]=sum[i-1]+a[i];
    rep1(i,n){
        sum[i]-=i;
        sum[i]+=k*MOD;
        sum[i]%=k;
    }
    int res=0;
    map<int,int> memo;
    //sort(sum.begin(),sum.end());
    int cur=1;int last=0;
    sum.push_back(MOD*10000000);
    if(k>n+1)k=n+1;
    rep(i,k){
        auto iter=memo.find(sum[i]);
        if (iter != end(memo) ) {
        iter->second++;
    } else {
        memo[sum[i]]=1;
    }
    }
    res+=memo[sum[0]]-1;
    rep1(i,n){
        //printf("sum[%lld]=%lld\n",i,sum[i]);
    }
    for(int i=1;i<n;i++){
        if(i+k-1<n+1){
        auto iter=memo.find(sum[i+k-1]);
        if ( iter != end(memo) ) {
        iter->second++;
    } else {
        memo[sum[i+k-1]]=1;
    }}
    memo[sum[i-1]]--;
        if(false)cur++;
        else{
            cur=memo[sum[i]];
            //last=sum[i];
            res+=cur-1;
            //cout<<res<<endl;
        }
        //printf("sum[%lld]=%lld\n",i,sum[i]);
    }
    //if(a[n]%k==1)res++;
    std::cout<<res<<endl;
    return 0;
}