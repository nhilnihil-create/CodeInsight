#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> W(N);
  for(int i=0; i<N; i++){
    cin>>W[i];
  }
  int ans=1e9;
  for(int i=0; i<N; i++){
    int sumb=0;
    int suma=0;
    for(int j=0; j<=i; j++){
      sumb+=W[j];
    }
    for(int k=i+1; k<N; k++){
      suma+=W[k];
    }
    ans=min(ans,abs(sumb-suma));
  }
  cout<<ans<<endl;
}