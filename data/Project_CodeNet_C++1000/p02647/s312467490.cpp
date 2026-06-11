#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int mod = 1e9+7;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i = 0;i < n;i++) cin>>a[i];
  while(k--) {
    vector<int> b(n+1,0);
    for(int i = 0;i < n;i++) {
      int l = max(0,i-a[i]);
      int r = min(n-1,i+a[i]);
      b[l]++;
      b[r+1]--;
    }
    bool changed = false;
    for(int i = 0;i < n;i++) {
      changed |= (a[i]!=b[i]);
      a[i] = b[i];
      b[i+1] += b[i];
    }
    if(!changed)
      break;
  }
  for(int i = 0;i < n;i++)
    cout<<a[i]<<" ";
  cout<<"\n";
  return 0;
}