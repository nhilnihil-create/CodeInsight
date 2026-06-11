#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  int result = 0;
  cin >> N;
  cin >> S;
  int A[N];
  int c = N;
  for(int b = 0;b < c;b++){
    
  for(int a = 0;a < c;a++)A[a] = 0;
A[0] = N;
  
 int i = 1, j = 0;
    
 while (i < N) {
   while (i+j < N && S[j] == S[i+j]) ++j; // 右向きにjを伸ばしていく
   A[i] = j;
   if(result < j&&i >= j)result = j;
   if (j == 0) { ++i; continue;}
   int k = 1;
   while (i+k < N && k+A[k] < j) A[i+k] = A[k], ++k; // i~j間にkを走らせる
   i += k; j -= k;
 }
    S.erase(0,1);
    N -= 1;
  }
  
  cout << result << endl;
  
}