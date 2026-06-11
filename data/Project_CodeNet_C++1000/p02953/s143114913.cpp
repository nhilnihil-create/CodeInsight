#include <iostream>
#include <string>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int now = 0;
  bool flag = true;
  rep(i, n){
    int h;
    cin >> h;
    if (h == now) now = h;
    else if (h > now) now = h - 1;
    else{
      flag = false;
      break;
    }
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}