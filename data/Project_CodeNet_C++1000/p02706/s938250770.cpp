#include <bits/stdc++.h>
#include <string>
using namespace std;
static const double pi = 3.141592653589793;


int main(){
  int n, m, a = 0, b, ans = 0;
  cin >> n >> m;
  
  for (int i = 0; i < m; i++){
    cin >> b;
    a = a + b;
  }
  if(0 <= n - a){
    ans = n -a;
  }else{
    ans = -1;
  }
  
  cout << ans << endl;
  
}