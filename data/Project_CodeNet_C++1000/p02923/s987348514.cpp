#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int N;
  cin >> N;
  
  int maxj = 0;
  vector<int>A(N);
  
  rep(i,N)cin >> A[i];
  int nowj = 0;
  
  for(int i = 1; i < N; i++){
    if(A[i] <= A[i-1]){
      nowj++;
    }
    else{
      maxj = max(maxj,nowj);
      nowj = 0;
    }
  }
  maxj = max(nowj,maxj);
  cout << maxj << endl;
  
}