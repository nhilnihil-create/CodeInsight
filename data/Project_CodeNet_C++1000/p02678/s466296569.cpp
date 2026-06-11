#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);

  for(int i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  } 

  vector<vector<int>> s(2000001);
  bool hantei[2000001];
  int prev[2000001] = {0};
  int ans[2000001] = {0};
  for(int i = 0; i < M; i++) {
    s[A[i]].push_back(B[i]);
    s[B[i]].push_back(A[i]);
  }
  if(s[0].size() == 0) { cout << "No" << endl; return 0; } 
  queue<int> q;
  q.push(0);
  hantei[0] = true;
  while(!q.empty()) {
    int num = q.front(); q.pop();
    for(auto i : s[num]) {
      if(!hantei[i]) {
        hantei[i] = true;
        ans[i] = num;
        q.push(i);
      }
    }
  }
  printf("Yes\n");
  for(int i = 1; i < N; i++) {
    cout << ans[i] + 1 << endl; 
  }





  
  return 0;
}