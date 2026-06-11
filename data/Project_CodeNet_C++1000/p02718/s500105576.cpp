#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  double sum=0;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){cin >> A.at(i); sum = sum+A.at(i);}
  
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  
  double bunnbo = sum/(4*M);
  
  if(A.at(M-1)>=bunnbo){cout << "Yes" << endl;}
  else{cout << "No" << endl;}
  
    
}