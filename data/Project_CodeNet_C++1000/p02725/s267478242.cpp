#include <bits/stdc++.h>
using namespace std;

int main() {
int K,N;
  cin>>K>>N;
  vector<int> Ai(N);
  for(int i=0;i<N;i++){
    cin>>Ai[i]; 
    //cout<<Ai[i]<<endl;
  }
  int Asa;
  int ma=K-Ai[N-1]+Ai[0];
  for(int i=0;i<N-1;i++){
    //cout<<ma<<endl;
    Asa=Ai[i+1]-Ai[i];
    ma=max(ma,Asa);
  }
  cout<<K-ma;
}