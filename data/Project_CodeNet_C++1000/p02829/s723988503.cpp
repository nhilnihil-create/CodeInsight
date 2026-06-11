#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for(int i = (s); i < (int)(n); i++)
typedef long long ll;

int main(){
  int a, b;
  cin >> a >> b;
  if(a!=1&&b!=1){
    cout << "1" << endl;
  }
  else{
    if(a!=2&&b!=2){
      cout << "2" << endl;
    }
    else{
      cout << "3" << endl;
    }
  }

  return 0;
}