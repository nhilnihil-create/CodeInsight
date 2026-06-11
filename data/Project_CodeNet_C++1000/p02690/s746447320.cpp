#include<iostream>
using namespace std;
#define rep(i, a, n) for(long long int i = a; i < n; i++)
int main(){
  long long int a, b, c, x;
  cin >> x;
  rep(i, -118, 120){
    rep(j, -119, 119){
      c = i * i * i * i * i - j * j * j * j * j;
      if(c == x){
        a = i;
        b = j;
        break;
      }
    }
  }
  
  cout << a << ' ' << b;
}