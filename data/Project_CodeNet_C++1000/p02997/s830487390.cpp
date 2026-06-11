#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;cin>>N>>K;
  int MAX = (N-1)*(N-2)/2;

  if(K>MAX){
    cout<<"-1"<<endl;
    return 0;
  }

  int m_base = N-1;
  int M = m_base + (MAX-K);
  cout<<M<<endl;

  for(int i=2; i<=N; i++){
    cout<<1<<" "<<i<<endl;
    M--;
  }

  int p=2, q = p+1;
  while(M>0){
    cout<<p<<" "<<q<<endl;
    q++;
    if(q>N){
      p++;
      q = p+1;
    }
    M--;
  }
}