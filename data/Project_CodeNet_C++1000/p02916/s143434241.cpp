#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n-1);
  int i;
  for(i=0;i<n;i++) cin >> a[i];
  for(i=0;i<n;i++) cin >> b[i];
  for(i=0;i<n-1;i++) cin >> c[i];
  int cnt = 0;
  for(i=0;i<n-1;i++){
    if(a[i+1]==a[i]+1) cnt += c[a[i]-1];
  }
  for(i=0;i<n;i++) cnt += b[a[i]-1];
  cout << cnt << "\n";
  return 0;
}