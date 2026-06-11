#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  long long sum=0;
  vector<long long> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    sum+=A[i];
  }
  
  long long mind=sum;
  long long t=0;
  for(int i=0; i<N; i++){
    t+=A[i];
    mind=min(mind,abs(sum-2*t));
  }
  cout << mind << endl;
}