

#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
  cin >> N;
    vector<int> A(N);
  long long count = 0;
  long long k = 0;
  for(int a = 0;a < N;a++){
    cin >> A[a];
    count += A[a];
    if(a % 2 == 1)k += A[a];
  }
  
  cout << count - 2 * k << " "; 
  k = count - 2 * k;
  for(int a = 0;a < N - 1;a++){
   cout << A[a] * 2 - k << " ";
    k = A[a] * 2 - k;
    
  }
  
}