#include <bits/stdc++.h>
using namespace std;
int cnt;

void insertionSort(vector<int> &A, int n, int g){
  for(int i = g; i < n; i++){
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
  return;
}

void shellSort(vector<int> A, int n){
  cnt = 0;
  vector<int> G;
  G.push_back(1);
  while(*(G.end()-1) < A.size()/3){
    //G[i+1] = G[i]*3+1;
    G.push_back(*(G.end()-1)*3+1);
  }
  unsigned int m = G.size();
  reverse(G.begin(), G.end());

  cout << m << endl;;
  for(int i = 0; i < m-1; i++){
    cout << G[i] << " ";
  }
  cout << G[m-1] << endl;

  for(int i = 0; i < m; i++){
    insertionSort(A, n, G[i]);
  }
  cout << cnt << endl;

  for(int i = 0; i < n; i++){
    cout << A[i] << endl;
  }

}

int main(void){
  int N; cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  shellSort(A, N);
  return 0;
}