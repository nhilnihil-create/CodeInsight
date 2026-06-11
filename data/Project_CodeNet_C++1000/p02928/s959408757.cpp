#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,K;
  cin >> N >> K;
  vector<long long> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  
  long long right=0;
  long long all=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(A.at(i) > A.at(j)) all++;
    }
    for(int j=i+1;j<N;j++){
      if(A.at(i) > A.at(j)) right++;
    }
  }
 
  long long ans =0;
  long long tmp =0;
  long long div = pow(10,9) + 7;

  ans += right * K % div;
  ans += K * (K-1) / 2 % div * all % div;
//  ans += all % div * K * (K-1) / 2 % div; // This is wrong. Why?
  ans %= div;
  cout << ans << endl;
  
}