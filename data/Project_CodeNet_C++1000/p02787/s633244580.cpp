#include <bits/stdc++.h>
#define Int long long
#define pb push_back
using namespace std;


Int N,M,K;
Int X,Y,Z,D;
const int MAXN=105;
Int B,C;


struct DisJointSet{
    vector<int> SZ;
    vector<int> ID;
    int n;

    DisJointSet(int n){
        SZ.resize(n);
        ID.resize(n);
        this->n=n;
        
        for(int i=0;i<n;++i){
            ID[i]=i;
            SZ[i]=1;
        }
    }
    
    int find(int x){
        return (ID[x]==x ? x:find(ID[x]));
    }
    
    void Union_find(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return;
        if(SZ[x]>SZ[y]){
            ID[y]=x;
            SZ[x]+=SZ[y];
        }
        else{
            ID[x]=y;
            SZ[y]+=SZ[x];
        }
        return;
    }
};
map<Int,Int> dp;
Int health(Int x){
    if(x==1) return 1;
    if(dp.count(x)) return dp[x];
    return dp[x]=1+health(x>>1LL)*2LL;
}

int main()
{
       cin>>N>>M;
       vector<Int> A(M+1),B(M+1);
       for(int i=1;i<M+1;++i){
           cin>>A[i];
           cin>>B[i];
       }
       
       vector<Int> dp(N+1,1e12);
       dp[0]=0;
       for(int i=1;i<=N;++i){
           for(int j=1;j<M+1;++j){
               dp[i]=min(dp[i],(i>=A[j] ? dp[i-A[j]]+B[j]:B[j]));
               
           }
       }
       cout<<dp[N]<<"\n";
       
}