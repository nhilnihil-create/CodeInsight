#include <bits/stdc++.h>
using namespace std;

int main(){
 
  long long N,i,res,a;
  cin >> N;
  map<int,int> m;

  res = 0;
  for(i=0;i<N;i++){
    cin >> a;
    res += m[i-a];
    m[i+a]++;
  }
  
  cout << res << "\n";

  return 0;
}