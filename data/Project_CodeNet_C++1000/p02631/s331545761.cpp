#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  int a[n], x = 0;
  for (int i=0; i<n; i++) {
    cin>>a[i];
    x = x ^ a[i];
  }
  for (int i=0; i<n; i++) cout<<(x ^ a[i])<<' ';
  cout<<'\n';
}
