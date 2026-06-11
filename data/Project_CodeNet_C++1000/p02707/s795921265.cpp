#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N-1){
    int a;
    cin >> a;
    A[a-1]++;
  }
  rep(i,N) printf("%d\n",A[i]);
  return 0;
}