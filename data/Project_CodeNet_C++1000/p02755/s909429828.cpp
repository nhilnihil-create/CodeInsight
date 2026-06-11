#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
#define MOD 1000000007;
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  int A,B;
  cin>>A>>B;
  
  
  for(int i=1;i<=10000;i++){
    if((i*8)/100==A&&i/10==B){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}