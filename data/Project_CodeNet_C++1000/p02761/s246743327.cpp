#include<bits/stdc++.h>
using namespace std;

int pow(int p, int q){
  int re = 1;
  for(int  i = 0; i < q; i++){
    re *= p;
  }
  return re;
}

int keta(int p, int q){
  string s = to_string(p);
  return (int)(s[q - 1] - '0');
}

int main(){
  int n, m;
  cin >> n >> m;
  if(m == 0 && n == 1){
    cout << 0 << endl;
    return 0;
  }
  vector<pair<int, int>> cases(m);
  for(int i = 0; i < m; i++){
    cin >> cases[i].first >> cases[i].second;
  }
  for(int i = pow(10, n - 1); i < pow(10, n); i++){
    bool flag = true;
    bool flag1 = false, flag2 = false;
    for(int j = 0; j < m; j++){
      if(cases[j].first == 1 && cases[j].second == 0){
        if(n == 1){
          flag1 = true;
        }else{
          cout << -1 << endl;
          return 0;
        }
      }
      if(n == 1 && cases[j].first == 1 && cases[j].second != 0){
        flag2 = true;
      }
      if(keta(i, cases[j].first) != cases[j].second){
        flag = false;break;
      }
    }
    if(flag1 && flag2){
      cout << -1 << endl;
      return 0;
    }else if(flag1){
      cout << 0 << endl;
      return 0;
    }
    if(flag){
      cout << i << endl;
      return 0;
    }
  }
    cout << -1 << endl;
    return 0;
}