#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while(1){
    c -= b;
    if(c <= 0){
      cout << "Yes\n";
      return 0;
    }
    a -= d;
    if(a <= 0){
      cout << "No\n";
      return 0;
    }
  }
}
    