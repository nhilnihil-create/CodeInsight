#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin >> N;
  int A[N];
  for(int i = 0; i < N; i++)
    cin >> A[i];
  vector<int> ans;
  bool ans_bool = true;
  for(int i = 0; i < N; i++){
    if(A[i] % 2 == 0){
      ans.push_back(A[i]);
    }
  }
  int len = ans.size();
  for(int i = 0; i < len; i++){
    if(ans[i] % 3 != 0 && ans[i] % 5 != 0){
      ans_bool = false;
    }
  }
  if(ans_bool) cout << "APPROVED" << "\n";
  else cout << "DENIED" << "\n";
  return 0;
}
