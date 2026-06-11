#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>A(N);
  for(int i=0; i<N; i++)cin >> A.at(i);
  
  vector<int>B(N);
  for(int i =0; i<N; i++){
    B.at(A.at(i)-1)=i+1;
  }
  
  for(int i=0; i<N-1; i++){
    cout << B.at(i) << " ";
  }
  
  cout << B.at(N-1) << endl;
}