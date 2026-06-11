#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 174, task d, 2020/09/04
//ms,
/*
*/

int main(void){
  int N;
  string c;
  deque<int> r;
  deque<int> w;
  int ctr=0;

  cin >>N >>c;
  for(int i=0;i<N;i++){
    if(c[i]=='R') r.push_front(i);
    else w.push_back(i);
  }

  while(r.size()!=0 && w.size()!=0 && w.front()<r.front()){
    r.pop_front();
    w.pop_front();
    ctr++;
  }

  cout <<ctr<<endl;
  return 0;
}
/*
10分で考えたこと：入れ替えだけで解けるのでは？いやいやそんなはずは......
赤一色、白一色、w---wr---rの三択であることには気づけた。N+1択であることに気づきたい。
......手も足も出ない。これが簡単めの茶色問題は嘘だろ。

むむ。これ模範解答じゃなくてもいけるのでは？
なるほど、最初に考えた方法が合ってたな。
入れ替えは当然色変更を含む。
*/
