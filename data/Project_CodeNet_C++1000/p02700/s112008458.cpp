#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  rep(i,100){
    c -=b;
    if(c<=0){
      cout << "Yes" << endl;
      return 0;
    }
    a -=d;
    if(a<=0){
      cout << "No" << endl;
      return 0;
    }
  }
}
