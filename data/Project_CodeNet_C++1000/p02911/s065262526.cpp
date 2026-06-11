#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n,k,q;
  cin >> n >> k >> q;
  
  vector<int> a(q);
  for(int i=0; i<q; i++){
    cin >> a[i];
  }
  
  vector<int> p(n);
  for(int i=0; i<n; i++){
    p[i] = 0;
  }
  for(int i=0; i<q; i++){
    p[a[i]-1]++;
  }
  
  for(int i=0; i<n; i++){
    if(q-p[i] <= k-1){
      cout << "Yes" << endl;
    }
    if(q-p[i] >= k){
      cout << "No" << endl;
    }
  }
    
	return 0;
}
