#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  for(int i=0;i<N;i++) cin >> A.at(i);
  
  vector<int> B(N);
  for(int i=0;i<N;i++) cin >> B.at(i);
  
  vector<int> C(N-1);
  for(int i=0;i<N-1;i++) cin >> C.at(i);
  
  int ans=0;
  
  for(int i=0;i<N;i++){
    ans += B.at(A.at(i)-1);
  }
  for(int i=0;i<N-1;i++){
    if(A.at(i)+1 == A.at(i+1)) ans += C.at(A.at(i)-1);
  }
  
  cout << ans << endl;
}
