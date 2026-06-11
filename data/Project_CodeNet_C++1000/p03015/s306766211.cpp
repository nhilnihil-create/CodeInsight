#include <bits/stdc++.h>
using namespace std;
 
int main() {
string L;
  cin >> L;
  int k = L.length();
  vector<long long> A(k,0);//以下であると確定
  vector<long long> B(k,0);//以下かはわからない
  A[0] = 1;
  B[0] = 2;
  for(int a = 1;a < k;a++){
    if(L[a] == '0'){
     A[a] = A[a-1] * 3;
     B[a] = B[a-1]; 
    }else{
     A[a] = A[a-1] * 3 + B[a-1]; 
     B[a] = B[a-1] * 2;
    }
    A[a] %= 1000000007;
    B[a] %= 1000000007;
    
  }
  
 cout << (A[k-1] + B[k-1]) % 1000000007;
}
