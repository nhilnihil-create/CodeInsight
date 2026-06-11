#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N;
  
  cin >> N;
int sum = 0;
  vector<int>  W(N);
  for(int a = 0;a < N;a++){
    cin >> W[a];
    sum += W[a];
  }
  int k = 0;
  
  int result = 1000000;
  for(int a = 0;a < N;a++){
    k += W[a];
    if(abs(sum - k - k) < result)result = abs(sum - k - k);
    
  }
  cout << result << endl;
}
