#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> num(1e6+5,0);
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  for(int i=0;i<N;i++){
    int a=A[i];
    if(num[a]>=2){
      continue;;
    }
    while(a<=1e6+3){
      num[a]++;
      a+=A[i];
    }
  }
  int ans=0;
  for(int i=0;i<N;i++){
    if(num[A[i]]==1){
      ans++;
    }
  }
  cout << ans << endl;
}