#include <bits/stdc++.h>
using namespace std;
// 型エイリアス
using pii = pair<int, int>;
using tisb = tuple<int, string, bool>;
using vi = vector<int>;
using vii = vector<vi>;

int m;
long long cnt=0;
vi G;

int fib(int i){
  if(i == 0) return 1;
  if(i == 1) return 1;
  return fib(i-1) + fib(i-2);
}

void insertionSort(vi &A, int n, int g){
  for(int i=g; i<n; ++i){
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j-=g;
      ++cnt;
    }
    A[j+g] = v;
  }
}

void shellSort(vi &A, int n){
  int h=1;
  while(h <= n){
    G.insert(G.begin(), h);
    h = 3*h + 1;
  }
  m = G.size();

  for(int i=0; i<m; ++i) insertionSort(A, n, G[i]);
}

int main(){
  int n; cin >> n;
  vi A(n);
  for(int i=0; i<n; ++i) scanf("%d", &A[i]);

  shellSort(A, n);

  printf("%d\n", m);

  for(int i=0; i<G.size(); ++i){
    if(i>0) printf(" ");
    printf("%d", G[i]);
  }
  printf("\n");

  printf("%d\n", cnt);

  for(int i=0; i<n; ++i) printf("%d\n", A[i]);
}
