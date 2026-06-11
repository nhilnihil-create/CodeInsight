#include <bits/stdc++.h>

using namespace std;

int z_algorithm(string S){
  int A[S.size()];
  A[0] = S.size();
  int i = 1, j = 0;
  while (i < S.size()) {
    while (i+j < S.size() && S[j] == S[i+j]) ++j;
    A[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
    i += k; j -= k;
  }
  int mx=0;
  for(int i=1;i<S.length();i++){
    if(i>=A[i]&&A[i]>mx)mx=A[i];
  }
  return mx;
}

int main(){
  int n;
  string s;
  cin >> n >> s;
  int mx=0;
  for(int i=0;i<n;i++){
    mx=max(mx, z_algorithm(s.substr(i, s.length()-i)));
  }
  cout << mx << endl;
}

