#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M; cin >> N >> M; map<int,int> map; bool check = true; int ans =0;
  if (N == 1 && M == 0) {
    ans = 0; check = false;
  } else {
    for (int i =0; i<M; i++) {
      int a,b; cin >> a >> b; 
      if (map.count(a)) {
        if (map[a] != b) { ans = -1; check = false; } 
      } else { map[a] = b; }
      if (N != 1 && a == 1 && b == 0) {ans =-1; check = false;}
    }
  }
  
  if (!check) { cout << ans << endl; } 
  else {
    for (int i =1; i<=N; i++) {
      if (map.count(i)) {cout << map[i]; } 
      else { i ==1 ? cout << 1 : cout << 0; }
    }
  }
}