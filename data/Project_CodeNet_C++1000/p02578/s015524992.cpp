#include <bits/stdc++.h>
using namespace std;



int main() {
  
  int N;
  scanf("%d", &N);
  
  vector<int> v(N);
  for(int i=0;i<N;i++){
      scanf("%d", &v[i]);
  }

  long long S = 0;

  for(int i=1;i<N;i++){
    
    if (v[i-1] > v[i]){
      S += (v[i-1]-v[i]);  
      v[i] = v[i-1];
    }

  }

  printf("%lld\n", S);

  return 0;
}


