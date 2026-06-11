#include <bits/stdc++.h>
using namespace std;



int main() {
  
  int X, N;
  scanf("%d %d", &X, &N);

  if(N==0){
    printf("%d\n", X);
    return 0;
  }

  vector<int> p(N);
  for(int i=0;i<N;i++){
    scanf("%d", &p[i]);
  }
  
  int N_MAX = 100;
  vector<int> v(N_MAX+1);
  for(int i=0;i<N;i++){
    v[p[i]]=1;
  }
  
  for(int i=0;i<N+1;i++){
    if(X-i<0){printf("%d\n", -1);break;}
    if(v[X-i]==0){printf("%d\n", X-i);break;}
    if(X+i>N_MAX){printf("%d\n", N_MAX+1);break;}
    if(v[X+i]==0){printf("%d\n", X+i);break;}    
  }

  return 0;
}


