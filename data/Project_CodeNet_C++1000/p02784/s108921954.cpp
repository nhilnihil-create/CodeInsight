#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int H, N;
  cin >> H >> N;
  vector<long long int> A(N);
  long long int attack = 0;
  for(long long int i = 0; i < N; i++) cin >> A[i];
  for(long long int i = 0; i < N; i++) attack += A[i];
  if(H <= attack) cout << "Yes" << endl;
  else cout << "No" << endl;
}
