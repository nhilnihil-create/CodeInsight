#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >>b >>c;
  int k;
  cin >>k;
  for(int i=1;i<=k;i++){
    if(b<=a){
      b*=2;
    }
    else if(c<=b){
      c*=2;
    }
  }
  if(a<b&&b<c){
      cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}