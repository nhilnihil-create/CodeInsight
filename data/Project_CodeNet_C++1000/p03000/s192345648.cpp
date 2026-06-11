#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,X;
  cin>>N>>X;
  int Z=1,A=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A+=a;
    if(A>X){
      break;
    }
    Z++;
  }
  cout<<Z<<endl;
}