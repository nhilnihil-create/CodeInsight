#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int N;
  cin >> N;
  
  vector<int> A(N + 1, 0);
  for (int i = 1; i <= N; i++){
    cin >> A.at(i);
  }
  
  vector<int> ans(N + 1, 0);
  for (int i = 1; i <= N; i++){
    ans.at(A.at(i)) = i;
  }
  
  for (int i = 1; i <= N; i++){
    cout << ans.at(i) << ' ';
  }
  
  cout << endl;
}