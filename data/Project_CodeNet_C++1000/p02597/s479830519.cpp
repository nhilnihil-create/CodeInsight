#include <iostream>
#include <vector>
using namespace std;

int main(void){
  int n,l,r,ans=0;
  vector<char> v;
  
  cin >> n;
  for (int i=0; i<n; i++){
    char c; cin >> c;
    v.push_back(c);
  }
  l = 0; r = n-1;
  while (1){
    while (1){
      if (l>n || v[l]=='W') break;
      l++;
    }
    while (1){
      if (r<=0 || v[r]=='R') break;
      r--;
    }
    if (l>=r) break;
    v[l++]='R'; v[r--]='W';
//    for (int i=0; i<n; i++) cout << v[i];
//    cout << endl;
    ans++;
  }
  cout << ans << endl;
  return 0;
}