#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> l(n);
  for(int i = 0; i < n; i++) cin >> l[i];
  int cnt = 0, sum = 0;
  for(int i = 0; i < n; i++){
    sum += l[i];
    if(sum <= x){
      cnt++;
    }
  }
  cout << cnt + 1 << endl;
  return 0;
}