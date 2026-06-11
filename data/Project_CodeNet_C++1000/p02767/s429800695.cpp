#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  
  
  for(int i=0; i<n; i++) cin >> x[i];
  sort(x.begin(), x.end());
  
  int p = x[0];
  ll sum = 1e11;
  while(p<=x[n-1]){
    ll tmp = 0;
    for(int i=0; i<n; i++){
      tmp += (x[i]-p)*(x[i]-p);
    }
    sum = min(sum, tmp);
    p++;
  }
  
  cout << sum << endl;
  
  
  return 0;
}