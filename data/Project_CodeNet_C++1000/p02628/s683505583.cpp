#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  
  vector<int> x(n);
  for(int i=0; i<n; i++){
    cin >> x.at(i);
  }
  sort(x.begin(), x.end());
  
  int sum=0;
  for(int i=0; i<k; i++)
    sum += x.at(i);
  
  cout << sum << endl;
  
  
  
}
