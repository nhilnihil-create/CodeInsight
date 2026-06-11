#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>A(N+1);
  vector<int>B(N);
  for(int i=0; i<N+1; i++)cin >> A.at(i);
  for(int i=0; i<N; i++)cin >> B.at(i);
  
  int64_t ans=0;
  int m;
  for(int i=N-1; i>=0; i--){
    m = min(A.at(i+1), B.at(i));
    ans += m;
    B.at(i) -= m;
    
    m= min(A.at(i), B.at(i));
    ans += m;
    A.at(i) -=m;
  }
  
  cout << ans << endl;
}
