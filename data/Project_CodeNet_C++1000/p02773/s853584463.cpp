#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 155, task c, 2020/08/13
//ms,
/*
*/

int main(void){
  map<string, int> cddt;
  int N;
  int max_vote;

  cin >>N;
  for(int i=0;i<N;i++){
    string tmp;
    cin >>tmp;

    if(cddt.count(tmp)) cddt[tmp]++;
    else cddt[tmp]=1;
  }

  max_vote=0;
  for(pair<string, int> p:cddt){
    string key = p.first;
    int value = p.second;

    max_vote = max(max_vote, value);
  }

  for(pair<string, int> p:cddt){
    string key = p.first;
    int value = p.second;

    if(value==max_vote) cout <<key<<endl;
  }

  return 0;
}
/*
mapを使おうとしたけどもしかしてsetの方がよかった？
*/
