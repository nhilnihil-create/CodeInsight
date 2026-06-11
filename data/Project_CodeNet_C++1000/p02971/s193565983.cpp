#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int N;
  cin >> N;
  
  vector<int>A(N);
  vector<int>B(N);
  rep(i,N){
    cin >> A[i];
    B[i] = A[i]; //ソート用にコピー
  }

  
  //最大値と２番目に大きい数を調べておく
  sort(B.begin(),B.end(),greater<>());
  int max_a = B[0];
  int max_b = B[1];
  
  rep(i,N){
    if(A[i] == max_a) cout << max_b << endl;
    else cout << max_a << endl;
  }
}