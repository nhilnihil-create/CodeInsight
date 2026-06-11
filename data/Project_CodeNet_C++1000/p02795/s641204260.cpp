#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,k,n;
  cin >> h >> k >> n;
  int d=max(h,k);
  if(n<=h || n<=k)cout << 1 << endl;
  else if(n%d)cout << n/d+1 << endl;
  else cout << n/d << endl;
}
