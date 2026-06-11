#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  long long A,B;
  cin>>A>>B;
  
  long long l;
  
  for(long long i=1;i<=B;i++){
    if((A*i)%B==0){
      l=A*i;
      break;
    }
  }
  
  cout<<l<<endl;
}