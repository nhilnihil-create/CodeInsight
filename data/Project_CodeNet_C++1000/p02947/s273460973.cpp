#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 137, task c, 2020/08/29
//ms,
/*
*/

int main(void){
  int N;
  vector<string> s;
  int64_t rec=1;
  int64_t ans=0;

  cin >>N;
  for(int i=0;i<N;i++){
    string tmp;
    cin >>tmp;
    s.push_back(tmp);
    sort(s[i].begin(), s[i].end());
    //cout <<s[i] <<endl;
  }

  sort(s.begin(), s.end());

  for(int i=0;i<N-1;i++){
    if(s[i]==s[i+1]) rec++;
    else{
      ans +=  rec*(rec-1)/2;
      rec=1;
    }
  }
  ans += rec*(rec-1)/2;

  cout <<ans;
  return 0;
}
/*
*/
