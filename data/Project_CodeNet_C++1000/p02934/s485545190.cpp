#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  double ans=0;
  for(int i=0;i<N;i++){
    ans+=(double)1/A[i];
  }
  cout << fixed << setprecision(6);
  cout << (double)1/ans << endl;
}