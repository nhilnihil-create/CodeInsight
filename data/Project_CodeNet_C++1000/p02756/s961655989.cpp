//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#include <stdio.h>

int main(){
  string S;
  cin >> S;
  int q;
  cin >> q;
  int count_t1 = 0;
  string f_1, f_2;
  rep1(i, q){
    int t;
    scanf("%d", &t);
    if(t == 1){
      count_t1 += 1;
    }
    else if(t == 2){
      int f;
      scanf("%d", &f);
      char c;
      scanf(" %c", &c);
      if(count_t1%2 == 0){//反転してない
        if(f == 1){
          f_1.push_back(c);
        }
        else if(f == 2){
          f_2.push_back(c);
        }
      }
      else{//反転してる
        if(f == 1){
          f_2.push_back(c);
        }
        else if(f == 2){
          f_1.push_back(c);
        }
      }
    }
  }

  if(count_t1%2 == 0){
    reverse(f_1.begin(), f_1.end());
    cout << f_1 + S + f_2;
  }
  else{
    reverse(f_2.begin(), f_2.end());
    reverse(S.begin(), S.end());
    cout << f_2 + S + f_1;
  }
}