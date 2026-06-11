#include<bits/stdc++.h>
using namespace std;

long long int min(long long int a, long long int b){
  return (a<b) ? a : b;
}

long long int max(long long int a, long long int b){
  return (a>b) ? a : b;
}
int main(){
  int n,k,q;
  cin >> n;
  vector<long long int> a(n);
  long long int res=0;
  long long int allxor=0;
  long long int j;
  for(long long int i=0; i<n; i++){
    cin >> a[i];
  }
  for(long long int i=0; i<n; i++){
    allxor ^= a[i];
  }
  for(long long int i=0; i<n; i++){
    a[i] &= ~allxor;
  }
  long long int rank=0;
  for(long long int i=59; i>=0; i--){
    for(j=rank; j<n; j++){
      if(a[j] & (1LL << i)) break;
    }
    if(j==n){
      continue;
    }
    if(j>rank) a[rank]^=a[j];
    for(j=rank+1; j<n; j++){
      a[j] = min(a[j], a[j]^a[rank]);
    }
    rank++;
  }
  long long int x = 0;
  for(long long int i=0; i<n; i++){
    x = max(x, x^a[i]);
  }
  res = (x*2) + allxor;
  cout << res << endl;
  //for(long long int i=0; i<n; i++){
  //  cout << a[i] << endl;
  //}
  return 0;
}
