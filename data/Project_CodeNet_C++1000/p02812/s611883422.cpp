#include<bits/stdc++.h>

using namespace std;

void solve(){
  int n;
  string str;
  cin >> n >> str;
  int cnt = 0;
  for(int i = 0; i <= n - 3; i++){
    if(str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C'){
      cnt ++;
    }
  }
  cout << cnt << endl;
}

int main(){
  
  solve();

}