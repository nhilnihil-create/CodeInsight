#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int N ;
  cin >> N;
  vector<int>A(N);
  vector<int>B(N-1);
  
  rep(i,N-1)cin >> B[i];
  
  ll ans = 0;
  
  rep(i,N-1){
    if(i == 0){
      A[i] = B[i];
      A[i+1] = B[i]; //最初の2個は決まっている
    }
    else{
      A[i+1] = B[i];
      A[i] = min(A[i],B[i]);
    }
    ans += A[i];
  }
  ans += A[N-1];
  cout << ans << endl;
}