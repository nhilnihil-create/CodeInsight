#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int a[k] = {};
  for(int i = 0; i < k; i++){
    a[i] = 1;
    n--;
  }
  a[0] += n;
  if(k == 1) cout << 0 << endl;
  else cout << a[0] - a[1] << endl;
}