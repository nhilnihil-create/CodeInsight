#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  
  vector<int> A(n), B(m);
  for(int i=0; i<n; i++)
    cin >> A.at(i);
  for(int i=0; i<m; i++)
    cin >> B.at(i);
  
  vector<long long> a(1, 0), b(1, 0);
  for(int i=1; i<n+1; i++)
    a.push_back(A.at(i-1)+a.at(i-1));
  for(int i=1; i<m+1; i++)
    b.push_back(B.at(i-1)+b.at(i-1));
  
  long long ans=0, j=m;
  
  for(int i=0; i<n+1; i++){
    if(a.at(i)>k)
      break;
    while(b.at(j) > k-a.at(i))
      j--;
    ans = max(ans, i+j);
  }
  
  cout << ans << endl;
}
