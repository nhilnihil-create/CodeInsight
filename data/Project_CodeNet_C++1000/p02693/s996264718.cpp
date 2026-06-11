#include <iostream>
#include <string>
#include <map> //map<string, int> cnt; key とvalue
#include <set>//  set<int> s;
#include <cstdlib>  // abs() for integer
#include <vector>
#define rep(i,n) for(int i = 0 ; i < (n); ++i)
using namespace std;
using ll = long long;
// g++ -std=c++11
int main(){
  int k,a,b;
  cin >> k >> a >> b;
  for(int i = a; i <= b; i++) if(i%k == 0){
    cout << "OK" << endl;
    return 0;
  }
  cout << "NG" << endl;
  return 0;
}