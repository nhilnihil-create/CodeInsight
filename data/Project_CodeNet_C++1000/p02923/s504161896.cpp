#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 139, task c, 2020/08/29
//ms,
/*
*/

int main(void){
  int N;
  int64_t h_left, h_right;
  int ans=0;
  int tmp_ans=0;

  cin >>N;
  cin >>h_left;
  for(int i=1;i<N;i++){
    cin >>h_right;
    if(h_left >= h_right) tmp_ans++;
    else {
      ans = max(ans, tmp_ans);
      tmp_ans=0;
    }
    h_left = h_right;
  }
  ans = max(ans, tmp_ans);
  cout <<ans <<endl;
  return 0;
}
/*
*/
