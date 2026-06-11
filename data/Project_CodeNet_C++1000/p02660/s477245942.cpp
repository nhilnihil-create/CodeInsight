#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 169, task d, 2020/09/02
//ms,
/*
*/

int main(void){
  int64_t N;
  vector<int> e_array;
  int ans=0;

  cin >>N;
  for(size_t i=2;i*i<=N;i++){
    int div_num=i;
    int tmp_e=0;
    while(N%div_num==0){
      N/=div_num;
      tmp_e++;
    }
    if(tmp_e != 0) e_array.push_back(tmp_e);
    //cout <<i <<" "<<tmp_e <<endl;
  }
  if(N!=1) e_array.push_back(1);

  for(size_t i=0;i<e_array.size();i++){
    int e=e_array[i];
    int counter=1;
    do{
      ans++;
      e-=counter;
    }while(e-(++counter)>=0);
  }

  cout <<ans<<endl;

  return 0;
}
/*
factorizationさえできれば勝ちじゃない？
オーダーもrootNでしょ。→正解。
素因数分解したあと、各素因数について定数時間で計算できそう。
でも算数ができなかったし実際に計算させても間に合いそうなのでそちらでいきます。
素因数分解できてなくて草。
*/
