
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
  string S,T;
  cin >> S >> T;
  if(S.size()+1 == T.size()){
    rep(i,S.size()){
      if(S[i]!=T[i]){
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}