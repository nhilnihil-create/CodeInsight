#include <bits/stdc++.h>
using namespace std;



int main() {

  int N;
  scanf("%d", &N);

  vector<long long> A(N);
  for (int i=0;i<N;i++){
    scanf("%lld", &A[i]);
  }


  
  sort(A.begin(), A.end(), greater<int>());

  priority_queue<long long> pq;
  pq.push(A[0]);

  long long S = 0;

  for (int i=1;i<N;i++){

    
    int X_MAX = pq.top();pq.pop();

    S += X_MAX;

    pq.push(A[i]);
    pq.push(A[i]);
    
  }

  printf("%lld\n", S);
  
  return 0;
}

