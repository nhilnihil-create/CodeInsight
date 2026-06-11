#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define debug(output) cout<<#output<<"= "<<output<<endl
using lint=long long;
int MOD=1000000007;
vector<lint> zeta_trans(vector<lint> const& array){
    int n=array.size();
    vector<lint> res(array);
    vector<bool> memo(n,true);
    for(int i=2;i<n;++i){
        if(!memo[i])continue;
        for(int j=(n-1)/i;j>0;--j){
            memo[i*j]=false;
            res[j]+=res[i*j];
        }
    }
    return res;
}
lint gcd(lint a,lint b){
    if(b==0)return a;
    return gcd(b,a%b);
}
signed main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<lint> array(1000001,0);
    rep(i,n)array[a[i]]++;
    vector<lint> fac=zeta_trans(array);
    bool flag=true;
    for(int i=2;i<=1000000;++i){
        if(fac[i]>1)flag=false;
    }
    lint c=0;
    rep(i,n){
        c=gcd(c,a[i]);
    }
    if(flag){
        cout<<"pairwise coprime"<<"\n";
    }
    else{
        if(c==1)cout<<"setwise coprime"<<"\n";
        else cout<<"not coprime"<<"\n";
    }
    return 0;
}