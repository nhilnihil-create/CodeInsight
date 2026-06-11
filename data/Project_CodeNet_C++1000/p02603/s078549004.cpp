#include <bits/stdc++.h>
using namespace std;

int a[200001];
int main(){
  long long v,N,i,p,po,n;
  cin >> N;
  
  po = 300;
  v = 1000;
  for(i=0;i<N;i++){
    cin >> p;
    if (p > po)
      v += (p - po) * (v / po);
    po = p;
  }
  
  cout << v << endl;
  
  return 0;
  
}