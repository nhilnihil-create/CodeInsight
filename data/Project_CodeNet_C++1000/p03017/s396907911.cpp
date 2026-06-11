#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,s1,s2,g1,g2;
  string map;
  cin >> N >> s1 >> s2 >> g1 >> g2 >> map;
  s1--; s2--; g1--; g2--; // 1-indexed -> 0-indexed
  int left = s1;          // 仮定よりs1 < s2
  int right= max(g1, g2); // 仮定よりg1 != g2

  bool reachable= true;
  int leapable= INT_MAX;
  for(int i=right; i>left; i--){
    if(map.at(i)=='#' && map.at(i-1)=='#'){
      reachable= false;
      break;
    }
    if(i-1 >= s2 && map.at(i)=='.' && map.at(i-1)=='.' && map.at(i-2)=='.'){
      leapable= i-1;
    }
  }

  string ans= (reachable && (g1 < g2 || leapable <= g2)) ? "Yes" 
                                                         : "No";
  cout << ans << endl;
}