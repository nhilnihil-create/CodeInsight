#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 157, task c, 2020/06/24
//ms,
/*
*/

int main(void){
  int N, M;
  int tmp_s=0;
  int tmp_c=0;
  vector<int> ans(3);
  vector<int> stable(3);
  int output=0;

  cin >>N >>M;
  for(int i=0;i<N;i++){
    stable[i]=0;
    ans[i]=0;
  }

  for(int i=0;i<M;i++){
    cin >>tmp_s >>tmp_c;
    //cout <<i <<endl;
    //for(int j=0;j<N;j++) cout <<ans[j];
    //cout <<endl;
    if(stable[N-tmp_s] && ans[N-tmp_s] != tmp_c) goto NOT_EXIST;
    else if(tmp_s == 1 && tmp_c == 0 && N != 1) goto NOT_EXIST;
    else {
      ans[N-tmp_s] = tmp_c;
      stable[N-tmp_s] = 1;
    }
  }

  if(ans[N-1] == 0 && N != 1) ans[N-1] = 1;


  for(int i=0;i<N;i++){
    output += ans[i];
    for(int j=i+1;j<N;j++) ans[j] *= 10;
  }
  cout <<output <<endl;
  return 0;

  NOT_EXIST:
    cout <<-1 <<endl;
    return 0;
}
/*
*/
