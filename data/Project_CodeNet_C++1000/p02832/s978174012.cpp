#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int index = 1;
  for (int i=0; i<n; i++) {
    int in;
    cin >> in;
    if(in == index){
      index++;
    }
  }
  if(index == 1){
    cout << -1 << endl;
    return 0;
  }
  int ans = n + 1 - index;
  cout << ans << endl;
}

