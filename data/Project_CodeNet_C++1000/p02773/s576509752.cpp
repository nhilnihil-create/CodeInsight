#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG


int has_key_using_count(map<string, int> &m, string key){
    if (m.count(key) == 0){
        //cout << "m doesn't have " << key << "." << endl;
        return 0;
    }
    else{
        //cout << "m has " << key << "." << endl;
        return m.at(key);
    }
}

int main() {
  map<string, int> dict;  ;
  ll N; 
  cin >> N;

  for(ll i=0; i< N; i++){
    string tmp;
    cin >> tmp;
    int val = has_key_using_count(dict, tmp);
    dict[tmp] = val+1;
  }
  
  ll max = 0;
  queue<string> buf;

  for (auto p : dict) {
    auto k = p.first;
    auto v = p.second;

    if(v > max){
      buf = queue<string>();
      buf.push(k);
      max = v;
    }else if(v == max){
      buf.push(k);
    }

  }

  while (!buf.empty()) {
    cout << buf.front() << endl;  // 先頭の値を出力
    buf.pop();  // 先頭の値を削除
  }

  return 0;
}
