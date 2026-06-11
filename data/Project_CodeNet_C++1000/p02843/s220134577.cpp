#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int x;
  cin >> x;
  if(x>=2000){
    cout << 1 << endl;
    return 0;
  }
  rep(a,20){
  rep(b,20){
  rep(c,20){
  rep(d,20){
  rep(e,20){
  rep(f,20){
    int tmp = 0;
    tmp += a*100;
    tmp += b*101;
    tmp += c*102;
    tmp += d*103;
    tmp += e*104;
    tmp += f*105;
    if(tmp == x){
      cout << 1 << endl;
      return 0;
    }
  }
  }
  }
  }
  }
  }
  cout << 0 << endl;
  return 0;
}