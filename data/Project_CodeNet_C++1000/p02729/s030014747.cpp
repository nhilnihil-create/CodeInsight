#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<iomanip>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int main(){
  int a, b, c = 0;
  cin >> a >> b;
  if(a >= 2){
    c += a * (a - 1) / 2;
  }
  if(b >= 2){
    c += b * (b - 1) / 2;
  }
  
  cout << c << "\n";
}