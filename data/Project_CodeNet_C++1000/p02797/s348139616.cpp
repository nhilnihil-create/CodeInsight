#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,K,S;
  cin>>N>>K>>S;
  for(int X=0;X<K;X++){
    if(X==K-1){
      cout<<S<<endl;
    }
    else{
      cout<<S<<" ";
    }
  }
  for(int X=K;X<N;X++){
    if(X==N-1){
      cout<<94541<<endl;
    }
    else{
      cout<<87693<<" ";
    }
  }
}