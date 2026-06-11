#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> X, L;
  for (int i = 0; i < N; i++){
    long long Xi, Li;
    cin >> Xi >> Li;
    X.push_back(Xi);
    L.push_back(Li);
  }

  vector<pair<long long, long long> > A;
  for (int i = 0; i < N; i++){
    A.push_back(make_pair(X[i] + L[i], X[i] - L[i]));
  }
  
  sort(A.begin(), A.end());

  int ans=1;
  long long p = A[0].first;
  for (int i = 1; i < N; i++){
    if (A[i].second >= p){
      ans++;
      p = A[i].first;
    }
  }

  printf("%d\n", ans);

}
