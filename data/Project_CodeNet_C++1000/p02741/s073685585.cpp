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
long long LCM(long long A,long long B){
  long long g=GCD(A,B);
  return A/g*B;
}
long long num_size(long long X){
  long long ans=0;
  while(true){
    if(X==0){
      break;
    }
    else{
      X/=10;
      ans++;
    }
  }
  return ans;
}
int main() {
  int K;
  cin>>K;
vector<int> v={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};


cout<<v[K-1]<<endl;
}