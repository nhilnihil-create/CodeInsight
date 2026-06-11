#define ll long long int
#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M = 1000001;
  int i,j,ct;
  int w=0,x;

  vector<int> c(M,0);
  cin >> N;
  for(i=0;i<N;i++){
    cin >> x;
    c[x] = 1;
    w = gcd(w,x);
  }

  if (w>1){
    cout << "not coprime" << endl;
    return 0;
  }
  
  for(i=2;i<M;i++){
    ct = 0;
    for(j=i;j<M;j+=i)
      ct += c[j];
    if (ct>1){
      cout << "setwise coprime" << endl;
      return 0;
    }
  }

  cout << "pairwise coprime" << endl;
  return 0;
}