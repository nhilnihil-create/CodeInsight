#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  long long A,B;
  cin>>A>>B;
  
  int G;
  
  for(int i=100000;i>=0;i--){
    if(A%i==0&&B%i==0){
      G=i;
      break;
    }
  }
  
  cout<<A*B/G<<endl;
}