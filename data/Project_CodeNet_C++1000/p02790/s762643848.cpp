#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  int a, b, c=1, d=1, x=0, y=0;
  cin >> a >> b;
  rep(i,a){
    x+=b*c;
    c*=10;
  }
  rep(i,b){
    y+=a*d;
    d*=10;
  }

  if(b>=a){
    cout << y << endl;
  }
  else{
    cout << x << endl;
  }

  return 0;
}