#include<iostream>
#include<stdio.h>
#include<string>
#include<typeinfo>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> s(M),c(M),v(N,-1);
    bool f=true;
    for (int i=0;i<M;i++){
        cin>>s[i]>>c[i];
        if (v[s[i]-1]==-1) v[s[i]-1]=c[i];
        else if (v[s[i]-1]!=c[i])  f=false;
    }
    for (int i=1;i<N;i++){
        if (v[i]==-1) v[i]=0;
    }
    if (N!=1){
        if (v[0]==-1) v[0]=1;
        if (v[0]==0) f=false;
    }
    else if (v[0]==-1) v[0]=0;
    int k=1,ans=0;
    for (int i=0;i<N;i++){
        ans+=v[N-1-i]*k;
        k=k*10;
    }
    if (f) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}