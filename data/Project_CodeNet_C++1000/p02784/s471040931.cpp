#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,N;
  cin >> H >> N;
  int sum=0;
  for(int i =0; i<N; i++) {
    int A[N]; cin >> A[i];
    sum += A[i];
  }
  if(H>sum) cout << "No" << endl;
  if(H<=sum) cout << "Yes" << endl;
}