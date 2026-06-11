#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> l(n-1, 0);
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      int l1=j-i-1;
      int l2=abs(x-i-1)+abs(y-j-1);
      l[min(l1, l2)]++;
    }
  }
  for(int i=0; i<n-1; i++){
    cout << l[i] << endl;
  }
  return 0;
}