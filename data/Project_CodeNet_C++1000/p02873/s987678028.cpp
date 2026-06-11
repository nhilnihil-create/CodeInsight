#include <bits/stdc++.h>
using namespace std;
int main(){string S;cin>>S;int64_t ans=0;vector<int>A(S.size()+1);for(int i=0;i<S.size();i++)if(S.at(i)=='<')A[i+1]=max(A[i+1],A[i]+1);for(int i=S.size()-1;i>=0;i--)if(S.at(i)=='>')A[i]=max(A[i],A[i+1]+1);for(int i=0;i<=S.size();i++)ans+=A[i];cout<<ans<<endl;}