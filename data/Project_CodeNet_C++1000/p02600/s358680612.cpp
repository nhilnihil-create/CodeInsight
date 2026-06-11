#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  if((X>=400)&&(X<=599)){
    cout << 8 << endl;
  }else if((X>=600)&&(X<=799)){
    cout << 7 << endl;
  }else if((X>=800)&&(X<=999)){
    cout << 6 << endl;
  }else if((X>=1000)&&(X<=1199)){
    cout << 5 << endl;
  }else if((X>=1200)&&(X<=1399)){
    cout << 4 << endl;
  }else if((X>=1400)&&(X<=1599)){
    cout << 3 << endl;
  }else if((X>=1600)&&(X<=1799)){
    cout << 2 << endl;
  }else{
    cout << 1 << endl;
  }
  return 0;
}
