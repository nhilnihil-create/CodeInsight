#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
 
typedef long long ll;

#define rep(i,n) for(ll i = 0; i < n; i++)

using namespace std;
 
const ll INF = ll(1e18)+1;
const double PI=3.14159265358979323846;

int main(){
  string s, ans="hi";
  cin >> s;
  bool ok;
  while(true){
    if(s == ans){
      ok = true;
      break;
    }
    if(s.size() < ans.size()){
      ok = false;
      break;
    }
    ans += "hi";
  }
  ok ? cout << "Yes" << endl : cout << "No" << endl;
}
