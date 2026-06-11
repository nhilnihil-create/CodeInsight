#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, N;
  cin >> K >> N;
  vector<int>A(N);
  vector<int>ans(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  
  sort(A.begin(), A.end());
  
  for(int i=0; i<N-1; i++){
    ans.at(i)=A.at(i+1)-A.at(i);
  }
  
  ans.at(N-1)=K-A.at(N-1)+A.at(0);
  
  sort(ans.begin(), ans.end());
  
  cout << K-ans.at(N-1) << endl;
  
}
