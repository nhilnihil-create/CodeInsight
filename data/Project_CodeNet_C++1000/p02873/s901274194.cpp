#include <bits/stdc++.h>
using namespace std;
/// 最大値を更新
template<class T> inline bool chkMax(T& a, T b){
  if(a < b){
    a = b;
    return true;
  }
  return false;
}

int main() {
  string str;
  long long kekka = 0;
  
  cin >> str;
  
  vector<int> vec(str.size()+1,0);
  
  for(int i = 0; i < str.size(); i++){
    if(str.at(i) == '<') vec.at(i+1) = vec.at(i) + 1;
  }

  for(int i = str.size()-1; i >= 0; i--){
    if(str.at(i) == '>') chkMax(vec.at(i), vec.at(i+1) + 1);
  }
  
  for(int i = 0; i < vec.size(); i++){
    kekka += vec.at(i);
  }
  
  cout << kekka;
}
