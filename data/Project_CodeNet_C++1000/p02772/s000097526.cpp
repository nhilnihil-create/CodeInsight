#include <bits/stdc++.h>
using namespace std;

int main() {
  bool ans=true;
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    if(x%2==0&&x%3!=0&&x%5!=0) ans=false;
  }
  if(ans) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}
