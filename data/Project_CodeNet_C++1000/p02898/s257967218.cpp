#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int cnt = 0, hig;
  for(int i=0; i<n; ++i){
    cin >> hig;
    if(hig >= k) ++cnt;
  }
  cout << cnt << endl;
}