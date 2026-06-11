#include <bits/stdc++.h>
using namespace std;



int main() {
  
  int N, M;
  long long K;
  scanf("%d %d", &N, &M);
  scanf("%lld", &K);

  vector<int> A(N);
  for(int i=0;i<N;i++){ scanf("%d", &A[i]); }

  vector<int> B(M);
  for(int i=0;i<M;i++){ scanf("%d", &B[i]); }

  vector<long long> SA(N+1);
  SA[0] = 0;
  for(int i=0;i<N;i++){ 
    SA[i+1]=SA[i]+A[i]; 
  }

  vector<long long> SB(M+1);
  SB[0] = 0;
  for(int i=0;i<M;i++){ 
    SB[i+1]=SB[i]+B[i]; 
  }

  // for(int i=0;i<N;i++){ printf("%d ",SA[i]); } printf("\n");
  // for(int i=0;i<M;i++){ printf("%d ",SB[i]); } printf("\n");

  int j = M;
  int SK = 0;
  for(int i=0;i<N+1;i++){
    
    while (SA[i]+SB[j]>K && j>-1){ j--; }
    if(j==-1){ break; }
    SK = max(SK, i+j);
  }


  printf("%d\n", SK);

  return 0;
}


