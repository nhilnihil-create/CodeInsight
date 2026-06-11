#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

int cnt;
void insertionSort(vector<int> &A,int g) {
  int n = A.size();
  REP(i,g,n) {
    int v = A[i];
    int j = i - g;
    while( j >= 0 && A[j] > v ) {
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(vector<int> &A) {
  int n = A.size();
  cnt = 0;
  int m = 100;
  vector<int> G(m,1);
  int v = (n>>1);
  int ptr = 0;
  while( v ) {
    G[ptr++] = v;
    v >>= 1;
  }

  rep(i,m) insertionSort(A,G[i]);
  
  cout << m << endl;
  //cout << cnt << "<"  << pow(n,1.5)<< endl;
  rep(i,m) {
    if( i ) printf(" ");
    cout << G[i];
  } puts("");
  cout << cnt << endl;
  rep(i,n) cout << A[i] << endl;
}

void solve(vector<int> &vec) {
  shellSort(vec);
}

int main() {
  if( 0 ) {
    srand((unsigned int)time(NULL));
    cout << 1000000 << endl;
    rep(i,1000000) cout << rand() << endl;
    return 0;
  }
  
  int n;
   cin >> n;
  vector<int> vec(n);
  rep(i,n) cin >> vec[i];
  solve(vec);
  return 0;
}

