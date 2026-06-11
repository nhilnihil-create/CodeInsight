#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int a,b;
  cin >> a >> b;
  if(1<=a && a<=9 && 1<=b && b<=9){
    cout << a*b << endl;
    return 0;
  }
  cout << -1 << endl;
}