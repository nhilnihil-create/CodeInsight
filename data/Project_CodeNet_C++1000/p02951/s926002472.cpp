#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int d = c-(a-b);
  if(d<0){
    cout << 0;
  }else{
    cout << d;
  }
}