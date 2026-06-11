#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
 
using namespace std;


int main(){
  int N,M;
  cin >> N >> M;
  int sum = 0;
  rep(i,M){
    int A;
    cin >> A;
    sum += A;
  }
  
  if(N-sum>=0){
    cout << N-sum << endl;
  }
  else{
    cout << -1 << endl;
  }
    
  
}