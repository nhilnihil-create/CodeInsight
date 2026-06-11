#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  int q;
  cin >> s >> q;
  deque<char> deq;
  for(int i = 0; i < s.size(); i++) deq.push_back(s[i]);
  vector<int> t(q), f(q);
  vector<char> c(q);
  for(int i = 0; i < q; i++){
    cin >> t[i];
    if(t[i] == 2) cin >> f[i] >> c[i];
  }
  
  bool flag = true;
  for(int i = 0; i < q; i++){
    if(t[i] == 1){
      flag = !flag;
      continue;
    }
    if(flag){
      if(f[i] == 1) deq.push_front(c[i]);
      else deq.push_back(c[i]);
    }else{
      if(f[i] == 1) deq.push_back(c[i]);
      else deq.push_front(c[i]);
    }
  }
  
  int size = deq.size();
  if(flag){
    for(int i = 0; i < size; i++){
      cout << deq.front();
      deq.pop_front();
    }
  }else{
    for(int i = 0; i < size; i++){
      cout << deq.back();
      deq.pop_back();
    }
  }
  cout << endl;
  return 0;
}