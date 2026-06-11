#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  for (int i=0;i<n;i++) {
    cin >> a.at(i); 
  }
  if(n==1){
    cout << "Yes" << endl;
    return 0;
  }
  int max=0;
  for (int i=0;i<n;i++) {
    if(max-1>a[i]){
      cout << "No" << endl;
      return 0;
    }
    if(max<a[i]){
      max=a[i];
    }
  }
  cout << "Yes" << endl;
}