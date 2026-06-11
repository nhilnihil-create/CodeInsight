#include<bits/stdc++.h>

using namespace std;

void solve(){
  int mini = 1e6;
  int n;
  cin >> n;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(x <= mini){
      cnt ++;
      mini = min(mini , x);
    }
  }
  cout << cnt << endl;
}

int main(){
  
  solve();

}