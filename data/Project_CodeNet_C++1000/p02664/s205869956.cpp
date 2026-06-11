#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

  string t;
  cin >> t;
  


  //t.replace(1, 2, "c");//開始位置，長さ，置き換え文字

  //pos = t.fine("a");//位置
  //len = s.length();//検索文字列の長さ
  //t.replace(pos, len, "c")
  
  std::replace(t.begin(), t.end(), '?', 'D');


  cout << t << endl;
  
}