#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int N,M,e[10000];
  scanf("%d%d", &N, &M);
  
  for(int i = 0; i < M; i++){
    scanf("%d", &e[i]);
  }
  
  int s=0;

  for(int i = 0; i < M; i++){
    s+=e[i];
  }
  
  N = N - s;
  
  if(N >= 0){
    cout << N << endl;
  }else{
    printf("-1");
  }
}

  