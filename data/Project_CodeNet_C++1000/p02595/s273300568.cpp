#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  long double N, D;
  cin >> N >> D;
  int ans = 0;
  for(int i = 0; i < N; i++){
    int x, y;
    cin >> x >> y;
    if(sqrt(pow(x,2) + pow(y,2)) <= D){
      ans++;
    }
  }
  cout << ans <<endl;
}