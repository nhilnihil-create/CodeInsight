#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 151, task C, 2020/06/25
//ms,
/*
*/

int main(void){
  int N, M;
  int tmp_p;
  string tmp_S;
  vector<int> task_status(100000);
  /*
  ACed: -1
  else: more than 0, means how many WA
  */
  int ac_num=0;
  int pen_num=0;

  cin >>N >>M;
  for(int i=0;i<N;i++){task_status[i]=0;}

  for(int i=0;i<M;i++){
    cin >>tmp_p >>tmp_S;
    if(task_status[tmp_p-1]==-1) continue;

    if(tmp_S == "AC"){
      pen_num += task_status[tmp_p-1];
      task_status[tmp_p-1] = -1;
      ac_num++;
    }else task_status[tmp_p-1]++;
  }
  cout <<ac_num <<" " <<pen_num <<endl;

  return 0;
}
/*
*/
