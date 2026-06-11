#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int a,b;
  cin >> a >> b;
  if(a<b){
    rep(i,b)cout << a;
  }else{
    rep(i,a)cout << b;
  }
  cout << endl;

  return 0;
}
