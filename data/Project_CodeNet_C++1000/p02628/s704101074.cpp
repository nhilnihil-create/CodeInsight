#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N, K;
  scanf("%d %d", &N, &K);
  
  vector<int> v(N);
  for(int i=0;i<N;i++){
    scanf("%d", &v[i]);
  }
  
  sort(v.begin(), v.end());
  int S = accumulate(v.begin(), v.begin()+K, 0);
  printf("%d\n", S);
  
  return 0;
}