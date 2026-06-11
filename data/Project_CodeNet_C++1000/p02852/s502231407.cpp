#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int n, m;
string s;

int main(){
  cin >> n >> m >> s;
  
  vector<int> res(0);
  bool flag = true;
  int pos = n;
  while(pos){
    bool nukeru = false;
    
    for(int i = m; i >= 0; i--){
      //cerr << i <<" ";
      if(i == 0){
        nukeru = true;
        flag = false;
      }
      if(i > pos){
        continue;
      }
      int num = s.at(pos - i) - '0';
      if(num == 0){
        pos -= i;
        res.push_back(i);
        break;
      }
    }//cerr << endl;
    
    if(nukeru){
      break;
    }
  }
  reverse(res.begin(), res.end());
  if(flag){
    for(int x : res){
      cout << x << endl;
    }
  }else{
    cout << -1 << endl;
  }
  
  return 0;
}
