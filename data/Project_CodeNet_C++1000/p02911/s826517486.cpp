#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k,q; cin >> n >> k >> q;
  vector<int> a(q), b(n, k-q);
  for(int i=0; i<q; i++) {
    cin >> a[i];
    b[a[i]-1]++;
  }
  for(int i=0; i<n; i++) {
    cout << (b[i]>0 ? "Yes" : "No") << endl;
  }
  return 0;
}
