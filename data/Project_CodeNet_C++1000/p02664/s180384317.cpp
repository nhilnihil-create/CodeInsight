#include <iostream>
#include <string.h>
using namespace std;


int main(){
  
  string t;		//問題文の文字列T
  
  cin >> t;		//tに標準入力
  


  // size_tは配列の長さなどを表すための正の整数のデータ型
  size_t position_hatena;	//"?"の位置

  //文字列tに"?"がある限り、文字の置換処理を続ける
  while(t.find("?") != string::npos){
    if((position_hatena = t.find("?")) != string::npos){
    	t[position_hatena] = 'D';	//"?"の位置を'D'で置換
    }
  }  
  
  cout << t;
  
  return 0;
}