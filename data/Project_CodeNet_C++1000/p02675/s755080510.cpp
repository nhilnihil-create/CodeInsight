
#include <iostream>
#include <string>
#include <map> //map<string, int> cnt; key とvalue
#include <set>//  set<int> s;
#include <cstdlib>  // abs() for integer
#include <vector>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std;
using ll = long long;
/*
g++ -std=c++11
*/
int main(){
  int N,n;
  cin >> N;
  n = N %10;
  if(n==2||n==4||n==5||n==7||n==9) cout << "hon";
  else if(n==0||n==1||n==6||n==8) cout << "pon";
  else cout << "bon";
  return 0;
}