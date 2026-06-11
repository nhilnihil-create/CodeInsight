#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,d,i,j,a;
  cin >> N >> K;
  vector<int> A(N+1,0);
  for(i=0;i<K;i++){
    cin >> d;
    for(j=0;j<d;j++){
      cin >> a;
      A[a]++;
    }
  }
  int ct=0;
  for(i=1;i<=N;i++)
    if (A[i] == 0)
      ct++;
  
  cout << ct << endl;

  return 0;
}