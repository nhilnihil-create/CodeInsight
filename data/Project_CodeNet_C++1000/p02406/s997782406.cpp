#include<bits/stdc++.h>
using namespace std;
int n;
int x;
int i;
void CHECK_NUM();
void INCLUDE3();
void END_CHECK_NUM();
int main(){
  cin >> n;
  i=1;
  CHECK_NUM();
}
void CHECK_NUM(){
  x = i;
  if(x%3==0){
    cout << " " << i;
    END_CHECK_NUM();
  }else{
    INCLUDE3();
  }
}
void INCLUDE3(){
  if(x%10 == 3){
    cout << " " <<i;
    END_CHECK_NUM();
  }else{
    x/=10;
    if(x){
      INCLUDE3();
    }
    else{
      END_CHECK_NUM();
    }
  }
}
void END_CHECK_NUM(){
  if(++i<=n){
    CHECK_NUM();
  }else{
    cout << endl;
  }
}