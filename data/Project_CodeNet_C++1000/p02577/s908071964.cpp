//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  string n;
  cin >> n;
  int judge = 0;
  
  rep1(i, n.size()){
    judge += n[i]-'0';
  }
  if(judge % 9 == 0){
    cout << "Yes";
  } 
  else{
    cout << "No";
  }
}