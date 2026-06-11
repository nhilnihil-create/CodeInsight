#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  int a[100100];
  int s = 0;
  
  cin >> n >> m;
  
  for(int i = 0; i < m; i++){
    cin >> a[i];
    s += a[i];
  }
  if(s > n){
    cout << -1 << endl;
  }else{
    cout << n - s << endl;
  }
}