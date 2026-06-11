#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 136, task c, 2020/08/14
//ms,
/*
*/

int main(void){
  int N;
  vector<int64_t> h;
  string ans="Yes";

  cin >>N;
  for(int i=0;i<N;i++){
    int tmp;
    cin >>tmp;
    h.push_back(tmp);
  }

  for(int i=h.size()-1;i>0;i--){

    if(h[i] == h[i-1]-1) h[i-1]--;
    else if(h[i] >= h[i-1]) ;//do nothing
    else {
      ans = "No";
      break;
    }
  }

  cout <<ans;

  return 0;
}
/*
わからんけど後ろからやったら勝つんじゃない？？
だめだ、オーダーがNでは勝てない。
*/
