#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin>>A>>B;
  int tmp=A-2*B;
  if(tmp<0){
    cout<<0<<endl;
    return 0;
  }
  cout<<tmp<<endl;
}