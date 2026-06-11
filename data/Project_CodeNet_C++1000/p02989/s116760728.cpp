#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int combination(int x){
  
}

int main(){
  int N;
  cin >> N;
  vector<int>A(N);
  
  rep(i,N)cin >> A[i];
  sort(A.begin(),A.end());
  
  int a = A[N/2];
  int b = A[N/2 -1];
  
  cout << a - b << endl;
  
}