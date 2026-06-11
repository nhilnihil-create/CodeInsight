
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
  ll x,tmp,cnt = 0;
  cin >> x;
  tmp = 100;
  while(tmp < x) {
    cnt++;
    tmp += tmp/100;
  }
  cout << cnt << endl;
  return 0;
}