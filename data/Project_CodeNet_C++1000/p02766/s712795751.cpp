#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,K,M;cin>>N>>K;
  if(K==10)cout<<to_string(N).size()<<endl;
  else{
    for(M=0;N>0;M++){
      N/=K;
    }
    cout<<M<<endl;
  }
}
