//list index out of range エラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
  int N,M;
  int A;
  cin >> N >> M;
  rep1(i, M){
    cin >> A;
    N -= A;
    if(N<0){
      N = -1;
      break;
    }

  }


  cout << N;
}
