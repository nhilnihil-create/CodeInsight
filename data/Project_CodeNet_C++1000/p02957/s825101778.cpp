#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,K;
  cin>>A>>B;
  K = (A+B)/2;
  if((A+B)%2){
    cout<<"IMPOSSIBLE\n";
  }else{
    cout<<K<<endl;
  }
}