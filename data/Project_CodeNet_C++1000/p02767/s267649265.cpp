#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin >> N;
  vector<int> A(N);
  double ave = 0;
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
    ave += A.at(i);
  }
  ave /= N;
  long long P = round(ave);
  long long  ans = 0;
  for(int i = 0; i < N; i++)
    ans += (P - A.at(i)) * (P - A.at(i));
  cout << ans << endl;
  
}
  
      