#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int h,n;
  cin >> h >> n;
  vector<int> a(n);
  int tot = 0;
  rep(i,n){
    cin >> a[i];
    tot +=a[i];
  }
  if(tot<h)cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
