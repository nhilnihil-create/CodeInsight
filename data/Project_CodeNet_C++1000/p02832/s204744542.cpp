#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int Z=0,A=1;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a==A){
      A++;
    }
    else{
      Z++;
    }
  }
  if(Z==N){
    Z=-1;
  }
  cout<<Z<<endl;
}