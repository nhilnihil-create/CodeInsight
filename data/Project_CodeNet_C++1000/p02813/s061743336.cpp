#include <bits/stdc++.h>
using namespace std;

int N;
int Pk,Qk;

int dfs(vector<int> &A, vector<bool> seen, int depth, int count, vector<vector<int>> &perm){
  if(depth == N){
    perm.push_back(A);
    return count+1;
  }
  int same = 0;
  for(int i = 0; i < N; i++){
    if(seen[i]) continue;
    A[depth] = i+1;
    seen[i] = true;
    count = dfs(A,seen,depth+1,count,perm);
    seen[i] = false;
  }
  return count;
}

int main(){
  cin >> N;
  vector<int> P(N);
  vector<int> Q(N);
  for(int i = 0; i < N; i++) cin >> P[i];
  for(int i = 0; i < N; i++) cin >> Q[i];
  vector<bool> seen(N);
  vector<int> A(N);
  vector<vector<int>> perm = {};
  dfs(A,seen,0,0,perm);
  int Pk = 0;
  int Qk = 0;
  for(int j = 0; j < perm.size(); j++){
    int sameP = 0;
    int sameQ = 0;
    for(int i = 0; i < N; i++){
      if(P[i] == perm[j][i]) sameP += 1;
      if(Q[i] == perm[j][i]) sameQ += 1;
    }
    if(sameP == N) Pk = j;
    if(sameQ == N) Qk = j;
  }
  cout << abs(Pk-Qk) << endl;
}
