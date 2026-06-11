#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N;
  scanf("%d", &N);

  vector<int> v(N);
  for(int i=0;i<N;i++){
      scanf("%d", &v[i]);
  }

  if(N<3){
    printf("0");
    return 0;
  }

  sort(v.begin(), v.end());

  int S = 0;
  
  for(int i=0;i<N-2;i++){
    for(int j=i+1;j<N-1;j++){
      for(int k=j+1;k<N;k++){
        if(v[i]!=v[j] && v[j]!=v[k] && v[i]!=v[k] && v[k]<(v[i]+v[j])){
          S++;            
        }
      }
    }
  }

  printf("%d\n", S);
  
  return 0;
}