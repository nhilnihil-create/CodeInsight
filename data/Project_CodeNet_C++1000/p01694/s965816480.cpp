#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<numeric>
#include<queue>
using namespace std;


int main(void) {

  int n;
  while(cin >> n){
    if( n == 0 ) break;
    bool l = false;
    bool r = false;
    bool p = false;
    int cnt = 0;
    for(int i=0; i<n; i++){
      string s;
      cin >> s;
      if( s == "lu" ) l = true;
      if( s == "ru" ) r = true;
      if( s == "ld" ) l = false;
      if( s == "rd" ) r = false;

      if( l == r && l != p ){
        cnt++;
        p = !p;
      }

    }
    cout << cnt << endl;


  }


  return 0;
}








//