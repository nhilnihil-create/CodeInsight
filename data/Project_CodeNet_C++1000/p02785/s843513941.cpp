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


int main()
{
    
  cin>>N>>M;
  vector<Int> A(N);
  Int sum=0;
  for(auto &x:A) cin>>x,sum+=x;
  sort(A.rbegin(),A.rend());
  Int ans=0;
  
  for(int i=0;i<min(N,M);++i){
      ans+=A[i];
  }
  
  ans=sum-ans;
  ans=max(ans,0LL);
  cout<<ans<<"\n";
  
}