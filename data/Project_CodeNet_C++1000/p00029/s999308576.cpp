#include<iostream>
#include<string>
using namespace std;

int main(){

  int l, c, len, m_len, m_cnt;
  int cnt[500] = {};
  string str, word[500];

  while(cin >> str){
    for(int i=0; i<500; i++){
      if(word[i] == ""){
        word[i] = str;
        cnt[i] = 1;
        break;
      }
      else if(word[i] == str){
        cnt[i]++;
        break;
      }
    }
  }

  m_len = 0;
  m_cnt = 0;
  for(int i=0; word[i] != ""; i++){
    if(m_cnt < cnt[i]){
      m_cnt = cnt[i];
      c = i;
    }
    len = word[i].length();
    if(m_len < len){
      m_len = len;
      l = i;
    }
  }

  cout << word[c] << " " << word[l] << endl;

  return 0;
}