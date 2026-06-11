#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int n, m;
  cin >> n >> m;
  int total = 0;
  int count = 0;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    total += a[i];
  }
  
  
  for(int i = 0; i < n; i++){
    if(a[i] * 4 * m >= total) count++;
  }
  
  if(count >= m) cout << "Yes" << endl;
  else cout << "No" << endl;
  
} 