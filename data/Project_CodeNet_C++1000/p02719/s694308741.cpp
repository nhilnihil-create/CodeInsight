#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long N,K;
  cin>>N>>K;
  if(N>=K){
    if(abs(N%K-K)<N%K){
      cout<<abs(N%K-K)<<endl;
    }
    else{
      cout<<N%K<<endl;
    }
  }

  if(N<K&&K<=2*N){
    cout<<K-N<<endl;
  }
  if(K>2*N){
    cout<<N<<endl;
  }
}