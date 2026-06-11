#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>G;
int cnt;

void insertionSort(int A[], int n, int g) {
  for(int i = g; i < n; i++) {
    int v = A[i];
    int j = i - g;
    while( j >= 0 && A[j] > v) {
      A[j + g] = A[j];
      j -= g;
      cnt++;
    }
    A[j + g] = v;
  }
}

void shellSort(int A[], int n) {
  int h = 1;
  while(true) {
    if(h > n) break;
    G.push_back(h);
    h = 3*h +1;
  }

  for(int i = G.size() - 1; i >=0; i--) {
    insertionSort(A, n, G[i]);
  }
}


int main() {
  int A[1000000], n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin>>A[i];
  }

  cnt = 0;

  shellSort(A, n);

  cout<<G.size() <<endl;
  for (int i = G.size() - 1; i >= 0; i--) {
    cout<<G[i];
    if(i) cout<<" ";
  }
  cout<<endl<<cnt<<endl;
  for(int i = 0; i < n; i++) {
    cout<<A[i]<<endl;
  }

  return 0;
}

