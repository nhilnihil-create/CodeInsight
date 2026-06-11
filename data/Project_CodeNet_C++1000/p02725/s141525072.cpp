#include<bits/stdc++.h>
using namespace std;

int main(){
  long long k,n;
  cin >> k >> n;
  vector<long long> h(n);
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  long long sa = 0;
  for(int i = 0; i < n-1; i++){
    sa = max(sa, h[i+1] - h[i]);
  }
  sa = max(sa, h[0] + k - h[n-1]);
  cout << k - sa << endl;
}