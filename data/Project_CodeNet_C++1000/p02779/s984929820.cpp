#include <bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  set<int> S;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(S.count(a)){
      cout <<"NO";
      return 0;
    }
    else
      S.insert(a);
  }
  cout << "YES";
}