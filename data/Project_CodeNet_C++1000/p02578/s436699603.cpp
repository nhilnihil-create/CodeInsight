#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  long long r = 0;
  int h = 0;
  for(int x : a){
    if(x < h){
      r += h - x;
    } else {
      h = x;
    }
    //cout << "h: " << h << " r: " << r << endl;
  }
  cout << r;
  return 0;
}