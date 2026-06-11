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
  int X, N;
  cin >> X >> N;
  set<int> p;
  for(int i = 0; i < N; i++){
    int x;
    cin >> x;
    p.insert(x);
  }
  for(int i = 0; i < 1000; i++){
    if(!p.count(X - i)){
    cout << X - i <<endl;
    return 0;
    } else if(!p.count(X + i)){
      cout << X + i <<endl;
      return 0;
    }
  }
}