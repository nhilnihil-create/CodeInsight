#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  
  vector<int>a(M);
  for(int i=0;i<M;i++){
    cin >> a.at(i); 
  }
  
  for(int i=0;i<M;i++){
    N -= a.at(i);
  }
  
  if(N<0)N=-1;
  
  cout << N << endl;
  return 0;
}