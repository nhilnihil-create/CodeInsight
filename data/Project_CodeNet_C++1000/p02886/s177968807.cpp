#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i=0 ; i<n ; i++)
    cin >> d.at(i);
  
  int ans = 0;
  for (int i=0 ; i<n-1 ; i++){
    for (int j=i+1 ; j<n ; j++){
      ans += d.at(i)*d.at(j);
    }
  }
  
  cout << ans << endl;
}