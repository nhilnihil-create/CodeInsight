#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int d = a + b + c;
  if(d > 21){
    cout << "bust\n";
  }
  else{
    cout << "win\n";
  }
}
