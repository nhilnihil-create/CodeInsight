#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 143, task do, 2020/09/011
//ms,
/*
*/

int main(void){
  int N;
  vector<int> l;
  vector<int> record(1001, 0);
  int64_t ans=0;

  cin >>N;
  for(int i=0;i<N;i++){
    int tmp;
    cin >>tmp;
    l.push_back(tmp);
  }

  sort(l.begin(), l.end());
  for(int i=0;i<N;i++){
    for(int j=l[i];j<=1000;j++) record[j]++;
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j) continue;

      int a, b, c_psblty;
      a=l[i]; b=l[j];
      int right=min(a+b-1, 1000);
      int left=abs(b-a);
      c_psblty = record[right]-record[left];

      if(left<a && a<=right){ c_psblty--; /*cout <<"a"<<endl;*/}
      if(left<b && b<=right){ c_psblty--; /*cout <<"b"<<endl;*/}
      ans+=c_psblty;

      //cout <<i <<" "<<j<<" " <<a <<" "<<b <<" " <<left <<" " <<right<<" " <<record[left]<<" " <<record[right] <<endl;
    }
  }
  cout <<ans/6<<endl;

  return 0;
}
/*
制約が小さめだね、n^2は余裕。
a, bを決めたらcの条件は単純に決まるのでそれで全探索する。累積和も使う。
問題は21行目にあって、累積和でも解けて、正三角形周辺が問題。
さて。かぶってても使える場合、使えない場合を見分けないといけない。
カウンタを用意しようにもかぶり方が複雑すぎる。お手上げ。
*/
