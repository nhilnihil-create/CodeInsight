#include <iostream>
#include <vector>
using namespace std;
int main(){
  int h,n;
  cin >> h >> n;
  vector<int> a(n);
  int i;
  long long sum = 0;
  for(i=0;i<n;i++){
    cin >> a[i];
    sum += a[i];
  }
  if(sum>=h) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}