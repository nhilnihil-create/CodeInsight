#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N+1);
  for(int i = 0; i < N+1; ++i){
    cin >> A.at(i);
  }

  long ans = 0, sum = 0;
  for(int i = 0; i < N+1; ++i){
    sum += A.at(i);
  }

  long node = 1;
  for(int i = 0; i < N+1; ++i){
    ans += node;
    node = (node - A.at(i)) * 2;
    sum -= A.at(i);
    node = min(node, sum);
    if(node < 0){
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
}