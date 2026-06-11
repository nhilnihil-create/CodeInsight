#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,k=10000;
  cin>>N;
  vector<int> W(N);
  for(int &i:W)
    cin>>i;
  for(int i=1;i<N;i++){
    int S1=0,S2=0;
    for(int j=0;j<N;j++){
      if(j<i)
        S1+=W[j];
      else
        S2+=W[j];
    }
    k=min(k,abs(S1-S2));
  }
  cout<<k<<endl;
}