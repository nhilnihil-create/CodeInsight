#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
  int N, S;
  cin >> N;
  S=0;
  vector<int> W(N);
  vector<int> U(N-1);
  vector<int> V(N-1);
  vector<int> X(N-1);
  for (int i=0; i<N; i++) {
    cin >> W[i];
  }
  for (int j=0; j<N; j++) {
    S=S+W[j];
  }
  for (int k=0; k<N-1; k++) {
    U[k]=0;
    V[k]=0;
  }
  for (int l=0; l<N-1; l++) {
    for (int m=0; m<l+1; m++) {
      U[l]=U[l]+W[m];
    }
    V[l]=S-U[l];
  }
  for (int n=0; n<N-1; n++) {
    X[n]=max((U[n]-V[n]),(V[n]-U[n]));
  }
  sort(X.begin(),X.end());
  cout << X[0] << endl;
}