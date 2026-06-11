#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d;
  cin >> s;
  vector<int> dp(n, 0), x(n);
  for (int i = 0; i < n; i++){
    if(s[i] == '#'){
      x[i] = 0;
    }else{
      x[i] = 1;
    }
  }
  int flag = 1;

  if(c > d){
    flag = 0;
    for (int i = b - 2; i < d - 1; i++){
      if(x[i] == x[i+1] && x[i+1] == 1 && x[i+1] == x[i+2]){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      cout << "No\n";
      return 0;
    }
  }
  for (int i = a - 1; i < max(c, d) - 1; i++){
    if(x[i] == x[i+1] && x[i+1] == 0){
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}