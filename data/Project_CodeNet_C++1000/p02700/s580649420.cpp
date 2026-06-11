#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int A,B,C,D;//体力A攻撃力B体力C攻撃力D
  cin >> A >>B >>C>>D;
  while(true){
    C -= B;
    if(C<=0){
      cout<<"Yes"<<endl;
      break;
    }
    A -= D;
    if(A<=0){
      cout<<"No"<<endl;
      break;
    }
  }  
}