#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N,K;
  cin >> N >> K;
  if(K > (N-1)*(N-2)/2){
   cout << -1 << endl; 
  }else{
    int k = (N-1)*(N-2)/2 - K;
    cout << k + N - 1 << endl;
    for(int a = 1;a < N;a++){
      cout << 1 << " " << a + 1 << endl;
      
    }
    int n = 2;
    int m = 2;
    for(int a = 0;a < k;a++){
      m++;
      if(m == n)m++;
      if(m > N){
        m = n + 2;
        n++;
      }
      cout << n << " " << m << endl;
      
    }
    
  }
}