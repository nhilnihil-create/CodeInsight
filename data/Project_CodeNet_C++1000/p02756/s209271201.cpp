#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 158, task d, 2020/09/05
//ms,
/*
*/

int main(void){
  deque<char> s;
  deque<char> s_rev;
  int is_rev=0;
  string input_S;
  int q;

  cin >>input_S >>q;
  for(size_t i=0;i<input_S.size();i++){
    s.push_back(input_S[i]);
    s_rev.push_front(input_S[i]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin >>t;
    if(t==1) is_rev++;
    else{//t==2
      int f;
      char c;
      cin >>f >>c;
      if((f+is_rev)%2==1){
        s.push_front(c);
        s_rev.push_back(c);
      }else{
        s.push_back(c);
        s_rev.push_front(c);
      }
    }
  }

  for(size_t i=0;i<s.size();i++) {
    if(is_rev%2==0) cout <<s[i];
    else cout <<s_rev[i];
  }

  return 0;
}
/*
愚直にやるとどうか。
反転がO(N=s.size())のオーダー。
全体がO(NQ)で、これは間に合わない。
なので、dequeで実装してsとs_revを両方持っておけばいい。
で、現在どちらが本命かのフラグをもっておく。
→正解！
*/
