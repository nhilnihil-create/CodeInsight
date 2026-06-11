#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

long long i,j,k,n,m,N,H,W,K,ans,fact[10],temp;

vector<long long> A;

int main()
{
  cin>>N;
  for(i=0;i<N;i++)
  {
    cin>>j;
    A.push_back(j);
  }
  sort(A.begin(),A.end(),greater<long long>());
  
  ans=0;
  ans+=A[0];
  if(N==2)
  {
    cout<<ans;
    return 0;
  }
  
  i=1;
  for(j=2;j<N;)
  {
    ans+=A[i];
    j++;
    if(j==N) break;
    ans+=A[i];
    i++;
    j++;
  }
  
  cout<<ans;
  

}