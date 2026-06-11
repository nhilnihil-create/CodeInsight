#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<numeric>
using namespace std;


int main(void) {

  string s, p;
  cin >> s;
  for(int i=0; i<s.size(); i++) if( s[i]-'A' >= 0 && s[i]-'A' < 26 ) s[i] += 32;

  int cnt = 0;
  while(cin >> p){

    if( p == "END_OF_TEXT" ) break;
    if( s.size() != p.size() ) continue;

    for(int i=0; i<p.size(); i++) if( p[i]-'A' >= 0 && p[i]-'A' < 26 ) p[i] += 32;

    bool f = true;
    for(int i=0; i<p.size(); i++){
      if( s[i] != p[i] ){
        f = false;
        break;
      }
    }
    if( f ) cnt++;

  }
  cout << cnt << endl;


  return 0;
}