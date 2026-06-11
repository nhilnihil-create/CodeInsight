#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin>>A>>B;
  for(int i=0;i<1000000000;i++){
    if(abs(A-i)==abs(B-i)){
      cout<<i<<endl;
      goto OUT;
    }
  }
  cout<<"IMPOSSIBLE"<<endl;
  OUT:;
}
  