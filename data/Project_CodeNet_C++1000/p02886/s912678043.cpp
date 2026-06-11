#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> d(n);
  int i,j;
  int cnt = 0;
  for(i=0;i<n;i++) cin >> d[i];
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      cnt += d[i]*d[j];
    }
  }
  cout << cnt << "\n";
  return 0;
}