#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  int a,b;
  cin >> a >> b;
  int cnt=a;
  int n=1;
  
  if(b==1){
    cout << 0 << endl;
    return(0);
  }
  
  while(cnt < b){
    cnt += a-1;
    n++;
  }
  cout << n << endl;
  
  return(0);
}