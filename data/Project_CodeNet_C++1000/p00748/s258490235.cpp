#include<iostream>
#include<climits>
using namespace std;

#define MAX 1000000

int main()
{
  int triangle,tetra[MAX];
  int i,j,T;
  int dp[MAX],dpOdd[MAX];
  int n;
  T=0;
  tetra[0]=1;
  tetra[1]=4;
  triangle=1;
  for(i=2;triangle<MAX;i++){
    triangle+=i;
    tetra[i-1]=tetra[i-2]+triangle;
    T++;
  }

  for(i=0;i<MAX;i++)dp[i]=dpOdd[i]=INT_MAX;
  dp[0]=dpOdd[0]=0;
  for(i=0;i<T;i++){
    for(j=tetra[i]; j<MAX; j++){
      if(dp[j-tetra[i]]+1 < dp[j])
	dp[j]=dp[j-tetra[i]]+1;
      if(tetra[i]&1 && dpOdd[j-tetra[i]]+1 < dpOdd[j])
	dpOdd[j]=dpOdd[j-tetra[i]]+1;
    }
  }

  while(cin>>n,n){
    cout<<dp[n]<<" "<<dpOdd[n]<<endl;
  }
}