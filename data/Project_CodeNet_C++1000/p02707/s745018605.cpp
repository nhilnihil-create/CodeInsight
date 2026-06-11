#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A;
  cin>>N;
  vector<int> B(N);
  for(int i=0;i<N-1;i++){
    cin>>A;
    B.at(A-1)++; 
  }
  
  for(int i=0;i<N;i++){
    cout<<B.at(i)<<endl; 
  }
  
  
  return 0;
}
