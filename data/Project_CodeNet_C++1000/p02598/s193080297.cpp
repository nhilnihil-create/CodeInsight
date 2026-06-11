#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  int h=1e9+10,l=1;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  while(h > l+1){
    int m = (h+l)/2;
    int ans = 0;
    for(int i=0; i<N; i++){
      ans += (A[i]+m-1)/m - 1;
    }
    if(ans > K) l = m;
    else h = m;
  }
  if(h == 2){
    int ans = 0;
    for(int i=0; i<N; i++){
      ans += (A[i]+h-1)/h - 1;
    }
    if(ans <= K) h = 1;
  }
  cout << h;
  return 0;
}