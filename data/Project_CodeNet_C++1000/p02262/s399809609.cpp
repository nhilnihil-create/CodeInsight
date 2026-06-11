#include <bits/stdc++.h>
using namespace std;

int cnt;

void insertion_sort(vector<int> &A, int n, int g) {  
  for ( int i = g; i < n; i++ ) {
    int v = A[i];
    int j = i-g;
    while ( j >= 0 && A[j] > v ) {
      A[j+g] = A[j];
      j -= g;
      cnt++;
    }
    A[j+g] = v;    
  }
}

vector<int> shell_sort(vector<int> &A, int n) {
  vector<int> G;
  for ( int h = 1; ; ) {
    if ( h > n ) break;
    G.push_back(h);
    h = 3*h+1;
  }

  for ( int i = (int)G.size()-1; i >= 0; i-- ) {
    insertion_sort(A, n, G[i]);
  }

  return G;
}

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for ( int i = 0; i < n; i++ ) cin >> A[i];

  vector<int> G = shell_sort(A, n);

  cout << G.size() << endl;
  for ( int i = (int)G.size()-1; i >= 0; i-- ) {
    cout << G[i];
    if ( i ) cout << " ";
  }
  cout << endl;

  cout << cnt << endl;

  for ( int i = 0; i < n; i++ ) cout << A[i] << endl;
  
  return 0;
}

