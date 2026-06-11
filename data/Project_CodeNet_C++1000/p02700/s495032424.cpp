#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)
using namespace std;
using p=pair<int,int>;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >>d;
  while(a > 0){
    a=a-d;
    c=c-b;
  }
  if(c<=0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  

}