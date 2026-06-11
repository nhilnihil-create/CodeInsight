#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
  int k = 0;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N,-1);
  for(int a = 0;a < N;a++)cin >> A[a];
  
  for(int a = N;a >= 1;a--){
    k = 0;
   for(int b = a * (N / a);b >= 1;b -= a){
    if(b <= a){
     B[a-1] = (k - A[a-1] + 1000000000) % 2; 
    }else{
     k += B[b-1]; 
    }
   }
  }
  k = 0;
for(int a = 0;a < N;a++){
  if(B[a] == 1)k++;
}
  cout << k << endl;
  for(int a = 0;a < N;a++){
    if(B[a] == 1)cout << a+1 << " ";
    
  }
}