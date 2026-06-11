#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
  int k = 0;
  cin >> N;
  vector<int> A(N);
  for(int a = 0;a < N;a++)cin >> A[a];
  for(int a = 1;a < N-1;a++){
    if(A[a] > A[a-1]&&A[a] < A[a+1])k++;
    if(A[a] < A[a-1]&&A[a] > A[a+1])k++;
    
  }
  cout << k;
}