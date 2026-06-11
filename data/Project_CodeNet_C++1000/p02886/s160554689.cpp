#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  int ans = 0;
  for(int i=0; i<n-1; ++i) for(int j=i+1; j<n; ++j){
    ans += an[i] * an[j];
  }
  cout << ans << endl;
}