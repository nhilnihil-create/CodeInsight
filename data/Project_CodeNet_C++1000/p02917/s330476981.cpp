//Ai=min(Bi-1,Bi)

#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N ;
  long long sum ;
  cin >> N ;
  vector<long long> B(100,200000);
  for(int i=0;i<N;i++){
    cin >> B[i];
  }
  
  sum += B[0];
  
  for(int i=1;i<N-1;i++){
    sum += min(B[i-1],B[i]);
  }
  
  sum += B[N-2];
  
  
  cout << sum << endl;
}
