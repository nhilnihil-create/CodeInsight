#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,A,B,Q,R;
  cin>>N>>A>>B;
  Q=N/(A+B);
  R=N%(A+B);
  if(R>A){
    cout<<A*Q+A<<endl;
  }
  else{
    cout<<A*Q+R<<endl;
  }
}