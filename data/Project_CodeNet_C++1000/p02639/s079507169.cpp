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
  int x[5];
  int ans;
  rep(i,5){
    cin >> x[i]; 
    if(x[i] == 0) cout << i+1 << endl;
  }
  return 0;
}