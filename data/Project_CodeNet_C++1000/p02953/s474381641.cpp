#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> h(n);
  for(int i = 0; i < n; i++){
    cin >> h[i];
  }
  bool flag = true;
  for(int i = n - 1; i > 0; i--){
    if(h[i - 1] - 1 == h[i]) h[i - 1]--;
    else if(h[i - 1] - h[i] > 1) flag = false;
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}