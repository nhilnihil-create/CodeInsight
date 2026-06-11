#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  vector<int> l(n);
  for(int i = 0; i < n; ++i){
    cin >> l[i];
  }
  int c = 1;
  int res = 0;
  for(int i = 0; i < n; ++i){
    res += l[i];
    if(res <= x){
      c += 1;
    }else{
      break;
    }
  }
  cout << c;
}