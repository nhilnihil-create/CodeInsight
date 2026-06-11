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
  if(c > a - b){
  cout << c - a + b << "\n";
  }
  else{
    cout << "0\n";
  }
}
