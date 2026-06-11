#include <bits/stdc++.h>
using namespace std;

int main() {
  int K,A,B;
  cin>>K>>A>>B;
  for(int i=0; i<K; i++){
    if(A%K==0){
      cout<<"OK"<<endl;
      break;
    }
    A+=1;
    if(A>B){
      cout<<"NG"<<endl;
      break;
    }
  }
}