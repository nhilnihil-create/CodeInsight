#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>A(N);
  for(int i=0; i<N; i++)cin >> A.at(i);
  
  vector<int>B(N);
  for(int i=0; i<N; i++)B.at(i)=A.at(i);
  
  sort(B.begin(), B.end());
  int Bmax1 = B.at(N-1);
  int Bmax2 = B.at(N-2);
  
  for(int i=0; i<N; i++){
    if(A.at(i)==Bmax1)cout << Bmax2 << endl;
    else cout << Bmax1 << endl;
  }
  
}