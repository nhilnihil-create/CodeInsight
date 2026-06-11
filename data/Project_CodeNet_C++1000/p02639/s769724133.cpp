#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
  int N = 5;
  vector<int> v(N);
  
  for(int i=0;i<N;i++){
    scanf("%d", &v[i]);
  }

  int S = accumulate(v.begin(), v.end(), 0);  
  printf("%d\n", 15-S);


  return 0;
}