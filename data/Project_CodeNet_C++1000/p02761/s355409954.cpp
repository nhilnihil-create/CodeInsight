#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> s(m), c(m);
  for(int i = 0; i < m; i++) cin >> s[i] >> c[i];
  
  bool flag = false;
  for(int i = 0; i < 1005; i++){
    string num = to_string(i);
    if((int)num.size() != n) continue;
    bool ok = true;
    for(int j = 0; j < m; j++){
      if((num[s[j]-1] - '0') != c[j]) ok = false;
    }
    if(ok == true){
      cout << i << endl;
      flag = true;
      break;
    }
  }
  
  if(!flag) cout << -1 << endl;
  return 0;
}