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
  
  long long A,B,C,D;
  cin>>A>>B>>C>>D;
  
  long long all=B-A+1;
  
  long long sum_C=B/C-(A-1)/C;
  
  long long sum_D=B/D-(A-1)/D;
  
  long long x=C*D/GCD(C,D);
  
  long long sum_CD=B/x-(A-1)/x;
  
  cout<<all-sum_C-sum_D+sum_CD<<endl;
}