#include<bits/stdc++.h>
using namespace std;

int main(){
  long A,B;cin>>A>>B;
  long count;
  int X=min(A,B);
  for(int i=1;i<=X;i++){
    if(A%i==0 && B%i==0) count=i;
  }
  cout<<A*B/count<<endl;
}