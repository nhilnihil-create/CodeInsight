#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, a;
  cin >> N;  
  int A[N+1];
  for (int i=1; i<N+1; i++){
    A[i]=0;
  }
  for (int i=0; i<N-1; i++){
    cin >> a;
    A[a]++;
  }
  for (int i=1; i<N+1; i++){
    cout << A[i] << endl;
  }
}