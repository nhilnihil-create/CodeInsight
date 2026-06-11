#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int>A(N);
  for(int i=0; i<N; i++)cin >> A.at(i);
  vector<int>B(M);
  for(int i=0; i<M; i++)cin >>B.at(i);
  
  int a=0;
  int b=0;
  int jikan=0;
  for(int i=0; i<N; i++){
    if(jikan + A.at(i) > K)break;
    jikan += A.at(i);
    a++;
  }
  for(int i=0; i<M; i++){
    if(jikan + B.at(i)>K)break;
    jikan += B.at(i);
    b++;
  }
  
  int wa = a+b;
  while(a>0){
    jikan -= A.at(a-1);
    while(b<M){
      if(jikan + B.at(b)>K)break;
      jikan += B.at(b);
      b++;
    }
    a--;
    wa = max(wa, a+b);
    if(b==M)break;
  }
  
  cout << wa <<endl;
}