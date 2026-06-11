#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin>>n; char x[2*n];
  for (int i = 0; i < n; i++) cin >> x[2*i];
  for (int i = 0; i < n; i++) cin >> x[2*i+1];
  for (int i = 0; i < 2*n; i++) cout<<x[i];
  cout<<endl;
}