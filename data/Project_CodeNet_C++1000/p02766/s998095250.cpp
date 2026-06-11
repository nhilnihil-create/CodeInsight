#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  cin >> n>>k;
  int d=1;//桁数（最低1桁）
  int e=0;
  for(int i=1;i<100;i++){
    int f=std::pow(k,i);//k進数の桁が増える基準（初めてべき乗使う）
    e=f-1;
    if(e>n){//次にはいけない
      break;
    }
    else if(e<n){//次の桁可能
      d++;
  }
  }
  cout << d << endl;
}