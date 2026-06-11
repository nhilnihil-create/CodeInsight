#include <bits/stdc++.h>
using namespace std;


int main() {
  long N,K;
  cin>>N>>K;
  if(K>(N-1)*(N-2)/2){
    cout<<-1<<endl;
    return 0;
  }
  cout<<N-1+(N-1)*(N-2)/2-K<<endl;

  vector<vector<long>> a(N+1,vector<long>(N+1));
  for(int i=0;i<=N;i++)  a[i][i]=1;
  for(int i=0;i<N-1;i++){
    cout<<1<<" "<<i+2<<endl;
    a[1][i+2]=1;
    a[i+2][1]=1;
  }
  int k=0;

  while(k<(N-1)*(N-2)/2-K){
    int i=rand()%N+1;
    int j=rand()%N+1;
    if(a[i][j]==0){
      k++;
      a[i][j]=1,a[j][i]=1;
      cout<<min(i,j)<<" "<<max(i,j)<<endl;
    }
  }


}
